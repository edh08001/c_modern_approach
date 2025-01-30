/* This program encrypts a message by a set shift on the ascii table */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MESSAGE_SIZE 80
#define UCASE_LOWER_LIMIT 65
#define UCASE_UPPER_LIMIT 90
#define LCASE_LOWER_LIMIT 97
#define LCASE_UPPER_LIMIT 122

/***************************************************
 * Encrypts a message by shifting 'shift' number   *
 * of chars to the right on the ASCII table, and   *
 * wrapping if the shift exceeds 'z'               *
 ***************************************************/
void encrypt(char *message, int shift);

int main(int argc, char *argv[])
{
  char in, message[MESSAGE_SIZE];
  int index = 0, shift;

  for(int i = 0; i < MESSAGE_SIZE; i++)
    message[i] = ' ';

  printf("Enter a message to be encrypted: ");

  while((in = getchar()) != '\n'){
    message[index] = in;
    index++;
  }
  message[index] = '\0';


  printf("Enter a shift amount: ");
  scanf("%d", &shift);

  encrypt(message, shift);
  
  for(int i = 0; i < index; i++)
    printf("%c", message[i]);

  printf("\n");

  return EXIT_SUCCESS;
}

void encrypt(char *message, int shift)
{
  do {
    if (UCASE_UPPER_LIMIT >= *message && *message >= UCASE_LOWER_LIMIT){
      if (*message + shift > UCASE_UPPER_LIMIT){
        *message = (shift - (UCASE_UPPER_LIMIT - *message)) + (UCASE_LOWER_LIMIT - 1);
      } else {
        *message = *message + shift;
      }
    } 
    if (LCASE_UPPER_LIMIT >= *message && *message >= LCASE_LOWER_LIMIT){
      if (*message + shift > LCASE_UPPER_LIMIT){
        *message = (shift - (LCASE_UPPER_LIMIT - *message)) + (LCASE_LOWER_LIMIT - 1);
      } else {
        *message = *message + shift;
      }
    } 
  } while (*++message);
}

