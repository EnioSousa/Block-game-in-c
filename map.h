#ifndef MAP
#define MAP

#include <stdio.h>
#include <stdlib.h>

#include "errorMessage.h"
#include "piece.h"

#define MAPLIMIT '#'


/* board    -> Mapa de jogo
   height   -> Altura do mapa de jogo
   width    -> Largura do mapa de jogo
   arrPiece -> Array bidimensional de peças. Cada possição representa
               uma peça diferente
   num      -> Numero de peas diferentes
*/
typedef struct Map
{
  char **board;
  int height, width;

  Piece **arrPiece;
  int num;
  
} Map;

Map *newMap(int h, int w);
char **newBoard(int h, int w);
char *newCharArray(int w, char ch);
void defineBorder(char **board, int w, int h);
Piece **newPieceArray(int num);

#endif
