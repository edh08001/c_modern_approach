/* This program encrypts a message by a set shift on the ascii table */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MESSAGE_SIZE 80
#define UCASE_LOWER_LIMIT 65
#define UCASE_UPPER_LIMIT 90
#define LCASE_LOWER_LIMIT 97
#define LCASE_UPPER_LIMIT 122

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

  printf("Enter a shift amount: ");
  scanf("%d", &shift);

  for(int i = 0; i < index; i++){
    if (UCASE_UPPER_LIMIT >= message[i] && message[i] >= UCASE_LOWER_LIMIT){
      if (message[i] + shift > UCASE_UPPER_LIMIT){
        message[i] = (shift - (UCASE_UPPER_LIMIT - message[i])) + (UCASE_LOWER_LIMIT - 1);
      } else {
        message[i] = message[i] + shift;
      }
    } 
    if (LCASE_UPPER_LIMIT >= message[i] && message[i] >= LCASE_LOWER_LIMIT){
      if (message[i] + shift > LCASE_UPPER_LIMIT){
        message[i] = (shift - (LCASE_UPPER_LIMIT - message[i])) + (LCASE_LOWER_LIMIT - 1);
      } else {
        message[i] = message[i] + shift;
      }
    } 
  }
  
  for(int i = 0; i < index; i++)
    printf("%c", message[i]);

  printf("\n");

  return EXIT_SUCCESS;
}
