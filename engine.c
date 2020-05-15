#include "engine.h"

void start(Map *map)
{
  State *state = newState(map);

  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = ( 50%1000 ) * 1000000;

  int num = 0, cycle = 20;
  
  while( !state->gameOver )
    {
      playerInput(state, getch());

      if ( num%cycle==0 )
	forceDown(state);
      
      display(state);

      num++;
      
      nanosleep(&ts, NULL);
    }
}
