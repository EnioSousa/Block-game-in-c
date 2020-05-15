#include "interface.h"

void display(State *state)
{
  printMap(state->map);

  printPiece(state->piece, state->rotation, state->cur);

  refresh();
}

void printMap(Map *map)
{
  int iLim = map->height;
  int jLim = map->width;

  for( int i=0; i<iLim; i++ )
    {
      for( int j=0; j<jLim; j++ )
	{
	  addch(map->board[i][j]);
	  addch(' ');
	}

      addch('\n');
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

      pos.x = XSTART + p->x + rp.x;
      pos.y = YSTART + p->y + rp.y;
      
      rotateCoordinates(&rp, rotation);

      if ( piece->form[rp.y][rp.x]!='.' )
	{
	  move(pos.y, pos.x*2);
	  addch(piece->form[rp.y][rp.x]);	  
	}
    }

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

  
