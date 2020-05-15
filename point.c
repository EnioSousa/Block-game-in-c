#include "point.h"

Point *newPoint(int x, int y)
{
  Point *p = (Point *)calloc(1, sizeof(Point));

  if ( p==NULL )
    errorMessageMem("newPoint");

  p->x = x;
  p->y = y;

  return p;
}
