#include "piece.h"

Piece *newPiece(char *str)
{
  Piece *piece = (Piece *)calloc(1, sizeof(Piece));

  if ( piece == NULL )
    errorMessageMem("newPiece");
  
  piece->form = (char **)calloc(PIECELIM, sizeof(char *));

  if ( piece->form == NULL )
    errorMessageMem("newPiece");  

  for( int i=0; i<PIECELIM; i++ )
    {
      piece->form[i] = (char *)calloc(PIECELIM, sizeof(char *));

      if ( piece->form[i] == NULL )
	errorMessageMem("newPiece");
    }

  defineForm(piece, str);

  return piece;
}

void defineForm(Piece *piece, char *str)
{
  int size = strlen(str);

  int iLim = PIECELIM * PIECELIM;
  
  if ( size < iLim )
    {
      fprintf(stderr, "Wrong usage on defineForm\n");
      exit(EXIT_FAILURE);
    }

  for( int i=0; i<iLim; i++ )
    piece->form[i/PIECELIM][i%PIECELIM] = str[i];
}

void rotateCoordinates(Point *p, int rot)
{
  rot %= 360;

  /* Confição lida com rotações negativas i.e rotações no sentido dos
     ponteiros do relogio*/
  if ( rot < 0 )
    return rotateCoordinates(p, rot/90 == -2 ? -rot: 180 - rot);

  Point tp;
  tp.x = p->x;
  tp.y = p->y;

  switch( rot )
    {
    case 0:
      break;

    case 90:
      p->x = PIECELIM - tp.y - 1;
      p->y = tp.x;
      break;

    case 180:
      p->x = PIECELIM - tp.x - 1;
      p->y = PIECELIM - tp.y - 1;
      break;

    case 270:
      p->x = tp.y;
      p->y = PIECELIM - tp.x - 1;
      break;

    default:
      fprintf(stderr, "Invalid rotation in rotateCoordinates %d\n", rot);
      exit(EXIT_FAILURE);      
    }
      
      
    }
