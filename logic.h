#ifndef LOGIC
#define LOGIC

#include <stdio.h>
#include <stdlib.h>

#include "piece.h"
#include "map.h"

typedef struct State
{
  Point *cur, *start;

  Piece *piece;

  int rotation, gameOver, remove, score;

  Map *map;
  
}State;

State *newState(Map *map);
void resetState();
Piece *randomPiece(Piece **arrPiece, int num);

int possiblePossition(Map *map, Piece *piece, int rotation, Point *p);
int outOfBound(Map *map, Point *p);

void moveLeft(State *state);
void moveRight(State *state);
int moveDown(State *state);
void rotateLeft(State *state);
void rotateRight(State *state);

void playerInput(State *state, int key);

void forceDown(State *state);

void putPiece(Map *map, Piece *piece, int rotation, Point *p);

void checkComplete(State *state);
int lineComplete(Map *map, int y);
void changeLine(Map *map, int y);
  
void removeComplete(State *state);
void removeLine(Map *map, int y);


#endif
