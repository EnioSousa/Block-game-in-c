#include "map.h"

Map *newMap(int h, int w)
{
  Map *map = (Map *)calloc(1, sizeof(Map));

  if ( map==NULL )
    errorMessageMem("newMap");

  map->height = h;
  map->width = w;

  map->board = newBoard(h, w);

  map->num = 7;
  map->arrPiece = newPieceArray(map->num);

  return map;
}

char **newBoard(int h, int w)
{
  char **board = (char **)calloc(h, sizeof(char *));

  if ( board == NULL )
    errorMessageMem("newMap");

  for( int i=0; i<h; i++ )
    board[i] = newCharArray(w, ' ');

  defineBorder(board, w, h);

  return board;
}

char *newCharArray(int w, char ch)
{
  char *arr = (char *)calloc(w, sizeof(char));

  if ( arr==NULL )
    errorMessageMem("newCharArray");

  for( int i=0; i<w; i++ )
    arr[i] = ch;

  return arr;
}

void defineBorder(char **board, int w, int h)
{
  for( int i=0; i<h; i++ )
    {
      board[i][0] = MAPLIMIT;
      board[i][w-1] = MAPLIMIT;
    }

  for( int i=0; i<w; i++ )
    board[h-1][i] = MAPLIMIT;
}

Piece **newPieceArray(int num)
{
  Piece **arrPiece = (Piece **)calloc(num, sizeof(Piece *));

  if ( arrPiece==NULL )
    errorMessageMem("newPieceArray");

  arrPiece[0] = newPiece(".AA..AA.........");
  arrPiece[1] = newPiece("..B...B...B...B.");
  arrPiece[2] = newPiece(".C...C...CC.....");
  arrPiece[3] = newPiece("..D...D..DD.....");
  arrPiece[4] = newPiece("..E..EE..E......");
  arrPiece[5] = newPiece(".F...FF...F.....");
  arrPiece[6] = newPiece("..G..GG...G.....");

  return arrPiece;  
}
