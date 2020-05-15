#ifndef PIECE
#define PIECE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errorMessage.h"
#include "point.h"

#define PIECELIM 4

typedef struct Piece
{
  char **form;
  
}Piece;

Piece *newPiece(char *str);
void defineForm(Piece *piece, char *str);
void rotateCoordinates(Point *p, int rotation);

#endif
