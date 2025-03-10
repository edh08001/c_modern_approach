#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(struct part *part);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

int main(void)
{
    char code;

    for (;;) {
        printf("Enter operation code (i,s,u,p,d,r,q): ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code) {
            case 'i': insert(NULL);
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'd': dump();
                      break;
            case 'r': restore();
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}

void dump(void)
{
    FILE *fp; 
    struct part *cur = inventory;
    char file_name[NAME_LEN+1];
    printf("Enter file name to save data to: ");
    read_line(file_name, NAME_LEN);
    fp = fopen(file_name, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while (cur != NULL){
        fprintf(fp, "%d%s%c%d\n", 
                cur->number, cur->name, '\0', cur->on_hand);
        cur = cur->next;
    }
    fclose(fp);
}

void restore(void)
{
    FILE *fp;
    char file_name[NAME_LEN+1];
    char item_name[NAME_LEN+1];
    char ch;
    int item_number, on_hand, i;
    printf("Enter file name to load data from: ");
    read_line(file_name, NAME_LEN);
    fp = fopen(file_name, "rb");

    for (int j = 0; j < 2; j++) {
        struct part *new_node;
        i = 0;
        new_node = malloc(sizeof(struct part));
        fscanf(fp, "%d", &new_node->number);
        do {
            ch = fgetc(fp);
            new_node->name[i++] = ch;
        } while (ch != '\0');
        fscanf(fp, "%d", &new_node->on_hand);
        fgetc(fp); //remove new line
        
        insert(new_node);
    }
}

struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;

    return NULL;
}

void insert(struct part *part)
{
    struct part *cur, *prev, *new_node;
    if (part == NULL) {
        new_node = malloc(sizeof(struct part));
        if (new_node == NULL) {
            printf("Database is full; can't add more parts.\n");
            return;
        }

        printf("Enter part number: ");
        scanf("%d", &new_node->number);
    } else {
        new_node = part;
    }

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
    }

    if (part == NULL) {
        printf("Enter part name: ");
        read_line(new_node->name, NAME_LEN);
        printf("Enter quantity on hand: ");
        scanf("%d", &new_node->on_hand);
    }

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else {
        printf("Part not found.\n");
    }
}

void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void print(void)
{
    struct part *p;
    printf("Part Number   Part Name                         "
           "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
}
