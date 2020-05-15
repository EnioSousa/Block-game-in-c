#include "errorMessage.h"

void errorMessageMem(char *str)
{
  fprintf(stderr, "Alocação de memoria falhou em %s\n", str);
  endwin();
  exit(EXIT_FAILURE);
}
