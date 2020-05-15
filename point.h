#ifndef POINT
#define POINT

#include <stdlib.h>

#include "errorMessage.h"

typedef struct Point
{
  int x, y;
  
}Point;

Point *newPoint(int x, int y);

#endif
