#include <stdio.h>

#define CMD_NUM 9

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

void call_function(char* cmd);

struct {
  char *cmd_name;
  void (*cmd_pointer)(void);
} file_cmd[] = 
  {{"new",            new_cmd},
   {"open",           open_cmd},
   {"close",          close_cmd},
   {"close all",      close_all_cmd},
   {"save",           save_cmd},
   {"save as",        save_as_cmd},
   {"save all",       save_all_cmd},
   {"print",          print_cmd},
   {"exit",           exit_cmd}
  };

int main(void)
{
  call_function("new");
  return 0;
}

void call_function(char* cmd)
{
  int i;
  for (i = 0; i < CMD_NUM; i++){
    if (file_cmd[i].cmd_name == cmd)
      file_cmd[i].cmd_pointer();
  }
}

void new_cmd(void)
{
  printf("New CMD Called\n");
}

void open_cmd(void)
{
  printf("Open CMD Called\n");
}

void close_cmd(void)
{
  printf("Close CMD Called\n");
}

void close_all_cmd(void)
{
  printf("Close All CMD Called\n");
}

void save_cmd(void)
{
  printf("Save CMD Called\n");
}

void save_as_cmd(void)
{
  printf("Save As CMD Called\n");
}

void save_all_cmd(void)
{
  printf("Save All CMD Called\n");
}

void print_cmd(void)
{
  printf("Print CMD Called\n");
}

void exit_cmd(void)
{
  printf("Exit CMD Called\n");
}
