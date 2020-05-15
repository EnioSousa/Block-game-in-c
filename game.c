#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "map.h"
#include "engine.h"

int main()
{
  Map *map = newMap(18, 12);
  
  srand(time(NULL));
  
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  start(map);
  
  endwin();
  
  return 0;
}
