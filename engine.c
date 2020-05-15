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
	  

      if ( state->remove )
	removeComplete(state);
      
      if ( !num )
	{
	  forceDown(state);
	}
      
      display(state);

      num = (num + 1)%cycle;
      
      nanosleep(&ts, NULL);
    }
}
