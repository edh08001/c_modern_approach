#define NAME_SIZE 40

enum type {SS, EM};

struct pinball_machine {
  char name[NAME_SIZE + 1];
  int year, players;
  enum type type;
};
