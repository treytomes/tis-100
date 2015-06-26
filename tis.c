#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ncurses.h>

#include "util.h"
#include "program.h"

int main() {
  Program program;
  Program *p = &program;

  program_init(p);
  program_load_system(p, "./programs/divide.sys");
  program_load_code(p, "./programs/divide.tis");

  initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

  program_output(p);
  int code = getch();
  while (code != 'q') {
    program_tick(p);
    clear();
    program_output(p);
    code = getch();
  }

  endwin();
}
