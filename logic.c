#include "logic.h"

State *newState(Map *map)
{
  State *state = (State *)calloc(1, sizeof(State));

  if ( state==NULL )
    errorMessageMem("newState");

  state->start = newPoint(map->width/2 - 3, 0);
  
  state->cur = newPoint(state->start->x, state->start->y);

  state->piece = randomPiece(map->arrPiece, map->num);

  state->map = map;

  state->rotation = 0;

  state->gameOver = 0;
  
  return state;
}

void resetState(State *state)
{
  state->cur->x = state->start->x;
  state->cur->y = state->start->y;

  state->rotation = 0;

  state->piece = randomPiece(state->map->arrPiece, state->map->num);

  state->gameOver = possiblePossition(state->map, state->piece, state->rotation, state->cur)==0 ? 1: 0;
}

Piece *randomPiece(Piece **arrPiece, int num)
{
  int index = rand() % num;

  return arrPiece[index];
}

int possiblePossition(Map *map, Piece *piece, int rotation, Point *p)
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

      if ( piece->form[rp.y][rp.x]!='.' &&
	   ( outOfBound(map, &pos) || map->board[pos.y][pos.x]!=' ' ) )
	return 0;
    }

  return 1;
}

int outOfBound(Map *map, Point *p)
{
  return p->y >= map->height || p->y < 0 || p->x >= map->width || p->x < 0 ? 1: 0; 
}

void moveLeft(State *state)
{
  Point p;
  p.x = state->cur->x - 1;
  p.y = state->cur->y;

  state->cur->x += possiblePossition(state->map, state->piece, state->rotation, &p)==1 ? -1: 0;
  
}

void moveRight(State *state)
{
  Point p;
  p.x = state->cur->x + 1;
  p.y = state->cur->y;

  state->cur->x += possiblePossition(state->map, state->piece, state->rotation, &p)==1 ? 1: 0;  
}

int moveDown(State *state)
{
  Point p;
  p.x = state->cur->x;
  p.y = state->cur->y + 1;

  if ( possiblePossition(state->map, state->piece, state->rotation, &p) )
    {
      state->cur->y++;
      return 1;
    }

  return 0;
}

void rotateLeft(State *state)
{
  state->rotation += possiblePossition(state->map, state->piece, state->rotation+90, state->cur)==1 ? 90: 0;
}

void rotateRight(State *state)
{
  state->rotation += possiblePossition(state->map, state->piece, state->rotation-90, state->cur)==1 ? -90: 0;
}

void playerInput(State *state, int key)
{
  if ( key==ERR )
    return;

  switch(key)
    {
    case 'a':
      moveLeft(state);
      break;

    case 'd':
      moveRight(state);
      break;

    case 's':
      moveDown(state);
      break;

    case 'k':
      rotateLeft(state);
      break;

    case 'l':
      rotateRight(state);
      break;

    default:
      break;
    }
}

void forceDown(State *state)
{
  if ( !moveDown(state) )
    {
      putPiece(state->map, state->piece, state->rotation, state->cur);
      resetState(state);    
    }
}
  
void putPiece(Map *map, Piece *piece, int rotation, Point *p)
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

      if ( piece->form[rp.y][rp.x]!='.' && !outOfBound(map, &pos) )
	map->board[pos.y][pos.x] = piece->form[rp.y][rp.x];
    }
}
