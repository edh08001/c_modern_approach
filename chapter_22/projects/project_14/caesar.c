/* This program encrypts a message by a set shift on the ascii table */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MESSAGE_SIZE 80
#define FILE_EXT 4
#define EXT ".enc"
#define UCASE_LOWER_LIMIT 65
#define UCASE_UPPER_LIMIT 90
#define LCASE_LOWER_LIMIT 97
#define LCASE_UPPER_LIMIT 122

int main(int argc, char *argv[])
{
  char in, message[MESSAGE_SIZE], enc_file[MESSAGE_SIZE + FILE_EXT];
  int index = 0, shift;

  printf("Enter a file to be encrypted: ");

  while ((in = fgetc(stdin)) != '\n' && index < MESSAGE_SIZE)
        message[index++] = in;
  
  message[index] = '\0';

  enc_file[0] = '\0';


  FILE *fpr, *fpw; 
  fpr = fopen(message, "rb");
  strcat(enc_file, message);
  strcat(enc_file, EXT); 
  fpw = fopen(enc_file, "wb");

  printf("Enter a shift amount: ");
  scanf("%d", &shift);
  
    while ((in = fgetc(fpr)) != EOF){
        if (UCASE_UPPER_LIMIT >= in && in >= UCASE_LOWER_LIMIT){
            if (in + shift > UCASE_UPPER_LIMIT){
                //message[i] = (shift - (UCASE_UPPER_LIMIT - message[i])) + (UCASE_LOWER_LIMIT - 1);
                in = (shift - (UCASE_UPPER_LIMIT - in) + (UCASE_LOWER_LIMIT - 1));
            } else {
                //message[i] = message[i] + shift;
                in = in + shift;
            }
        } 
        if (LCASE_UPPER_LIMIT >= in && in >= LCASE_LOWER_LIMIT){
            if (in + shift > LCASE_UPPER_LIMIT){
                //message[i] = (shift - (LCASE_UPPER_LIMIT - message[i])) + (LCASE_LOWER_LIMIT - 1);
                in = (shift - (LCASE_UPPER_LIMIT - in)) + (LCASE_LOWER_LIMIT - 1);
            } else {
                //message[i] = message[i] + shift;
                in = in + shift;
            }
        }

        fputc(in, fpw);
    }
  
  return EXIT_SUCCESS;
}
