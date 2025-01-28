#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 50

/****************************************************
 * Represents the actual process of reading through *
 * the query and assigning the strings to the       *
 * reminder array                                   *
 ****************************************************/
int read_line(char s[], int n);

/****************************************************
 * Capitalizes every letter in the array. Requires  *
 * the array to be a null terminated string. Results*
 * undefined with no null termination               *
 ****************************************************/
void capitalize(char s[]);

/****************************************************
 * Censors the first array by a prespecified word   *
 * located in the second array                      *
 ****************************************************/
void censor(char s[], char c[]);

/****************************************************
 * Compares one string to the next and returns 0 if *
 * equal, below 0 if s < c, and above 0 if s > c    *
 ****************************************************/
int compare_string(char *s, char *c);

/****************************************************
 * Using a full file-name input by the user, extract*
 * the extension and place it into its own string   *
 ****************************************************/
void get_extension(const char *file_name, char *extension);

/****************************************************
 * Removes the filename, extension, and final / from*
 * a url provided by the user                       *
 ****************************************************/
void remove_filename(char *url);

/****************************************************
 * Tests whether the file name has the same         *
 * extension as the supplied extension string. This *
 * check is case agnostic.                          *
 ****************************************************/
bool test_extension(const char *file_name, char *extension);

/****************************************************
 * Builds a url to index by appending http://www.   *
 * to the beginning, and /index.html to the end of a*
 * supplied string. The total index url must not    *
 * exceed 50 characters                             *
 ****************************************************/
void build_index_url(const char *domain, char *index_url);

int main(int argc, char *argv[])
{

  int i, j;
  char s[N + 1];
  char c[] = "foo";
  char url[50] = "http://www.knking.com/index.html";
  char extension[20];
  char index_url[50];
  bool file_name_test;
 //read_line(s, N);

 //censor(s, c);

 //capitalize(c);

 //get_extension("happy.information", extension);

 //build_index_url("knking.com", index_url);

 //file_name_test = test_extension("test.txt", "txt");

  remove_filename(url);

  printf("%s\n", url);

  return EXIT_SUCCESS;

}

void remove_filename(char *url)
{
  for (int i = strlen(url); i >= 0; i--){
    if(url[i] == '/'){
      url[i] = '\0';
      break;
    }
  }
}

bool test_extension(const char *file_name, char *extension)
{
  char file_extension[20], test_extension[20];
  while(*file_name++ != '.')
  {
    if (*file_name == '\0')
    {
      *file_extension = *file_name;
      break;
    }
  }

  strcpy(file_extension, file_name);
  strcpy(test_extension, extension);

  capitalize(file_extension);
  capitalize(test_extension);

  if (strcmp(file_extension, test_extension) == 0) 
    return true;

  return false;
}

void build_index_url(const char *domain, char *index_url)
{
  strcat(index_url, "http://www.");
  strcat(index_url, domain);
  strcat(index_url, "/index.html\0");
}

void get_extension(const char *file_name, char *extension)
{
  while(*file_name++ != '.')
  {
    if (*file_name == '\0')
    {
      *extension = *file_name;
      break;
    }
  }

  strcpy(extension, file_name);
}

int read_line(char s[], int n)
{
  int in, i = 0;

  while((in = getchar()) != '\n'){
    if (i < n) {
      s[i++] = in;
    }
  }
  s[i] = '\0';
  return i;
}

void capitalize(char s[])
{
  char *p = s;
  while((*s++ = toupper(*p++)))
    ;
}

void censor(char s[], char c[])
{
  bool match = false;
  do {
    for (int i = 0; i < 3; i++){
      if (s[i] == c[i]) 
        match = true;
      else
        break;
    }
    if (match){
      s[0] = s[1] = s[2] = '*';
      match = false;
      s += 2;
    }
  } while (*++s);
}

int compare_string(char *s, char *c)
{
  do {
    if (*s == '\0')
      return 0;
  } while (*s++ == *c++);
  return s - c;
}

