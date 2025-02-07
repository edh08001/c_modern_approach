#include <stdio.h>
#include <stdbool.h>

#define COUNTRY_COUNT 32

struct country_code {
  char *country;
  int code;
};

/****************************************************************
 * find_code: find_code searches through an array of country    *
 *            code structs, and attempts to match the user      *
 *            supplied country code to one in the array. if     *
 *            found, find_code prints the country name. If not, *
 *            find_code prints an error message.                *
 ****************************************************************/
void find_code(struct country_code country_codes[], int n, int code);

int main(void)
{
  struct country_code country_codes[] = 
    {{"Argentina",              54}, {"Bangladesh",          880},
     {"Brazil",                 55}, {"Burma (Myanmar)",      95},
     {"China",                  86}, {"Colombia",             57},
     {"Congo, Dem. Rep. of",   243}, {"Egypt",                20},
     {"Ethiopia",              251}, {"France",               33},
     {"Germany",                49}, {"India",                91},
     {"Indonesia",              62}, {"Iran",                 98},
     {"Italy",                  39}, {"Japan",                81},
     {"Mexico",                 52}, {"Nigeria",             234},
     {"Pakistan",               92}, {"Philipines",           63},
     {"Poland",                 48}, {"Russia",                7},
     {"South Africa",           27}, {"South Korea",          82},
     {"Spain",                  34}, {"Sudan",               249},
     {"Thailand",               66}, {"Turkey",               90},
     {"Ukraine",               380}, {"United Kingdom",       44},
     {"United States",           1}, {"Vietnam",              84}};

  find_code(country_codes, COUNTRY_COUNT, 251);
  find_code(country_codes, COUNTRY_COUNT, 2);
}

void find_code(struct country_code country_codes[], int n, int code)
{
  int i;
  bool found = false;
  for (i = 0; i < n; i++)
  {
    if (country_codes[i].code == code){
      printf("Code %d belongs to %s\n", code, country_codes[i].country);
      found = true;
      break;
    }
  }
  if (!found)
    printf("No Country Code of value %d found in the database\n", code);
}
