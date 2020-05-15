#include "interface.h"

void display(State *state)
{
  printMap(state->map);

  printPiece(state->piece, state->rotation, state->cur);

  printScore(state->score, state->map->height, state->map->width);
  
  refresh();
}

void printMap(Map *map)
{
  move(YSTART, XSTART);
  
  int iLim = map->height;
  int jLim = map->width;
  
  for( int i=0; i<iLim; i++ )
    {
      move(YSTART+i, XSTART);
      
      for( int j=0; j<jLim; j++ )
	{
	  addch(map->board[i][j]);
	  addch(' ');
	}
    }

  move(XSTART, YSTART);
}

void printPiece(Piece *piece, int rotation, Point *p)
{
  int iLim = PIECELIM * PIECELIM;

  Point rp, pos;

  for( int i=0; i<iLim; i++ )
    {
      rp.x = i%PIECELIM;
      rp.y = i/PIECELIM;

      pos.x = p->x + rp.x;
      pos.y = p->y + rp.y;
      
      rotateCoordinates(&rp, rotation);

      if ( piece->form[rp.y][rp.x]!='.' )
	{
	  move(YSTART + pos.y, XSTART + pos.x*2);
	  addch(piece->form[rp.y][rp.x]);	  
	}
    }

  move(XSTART, YSTART);
}

void printScore(int score, int y, int x)
{
  move(0, 0);

  printw("Score = %d", score);
  
  move(XSTART, YSTART);
}

void printMapD(Map *map)
{
  int iLim = map->height;
  int jLim = map->width;
  
  for( int i=0; i<iLim; i++ )
    {
      for( int j=0; j<jLim; j++ )
	{
	  putchar(map->board[i][j]);
	  putchar(' ');
	}

      putchar('\n');
    }
}

  
