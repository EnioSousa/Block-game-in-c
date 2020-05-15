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
	  
      /* Condição verifica se existe alguma linha para remover*/
      if ( state->remove )
	removeComplete(state);

      /* Condição verifica se podemos avançar com a peça para baixo*/
      if ( !num )
	forceDown(state);
      
      display(state);

      num = (num + 1)%cycle;
      
      nanosleep(&ts, NULL);
    }

  move(0, 0);

  system("clear");
  printw("Your score was %d", state->score);

  refresh();
  
  sleep(5);
}
