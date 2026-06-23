#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

struct grid_type {
  int grid[NUMROWS][NUMCOLS];
  int rows;
  int cols;
  int cellSize;
};

Grid create(void)
{
  Grid g = malloc(sizeof(struct grid_type));
  if (g == NULL)
    terminate("Error in create: grid could not be created.");
  g->rows = NUMROWS;
  g->cols = NUMCOLS;
  g->cellSize = 30; // cell size for 300 x 600

  return g;
}

void destroy(Grid g)
{
  free(g);
}

void initialize(Grid g)
{
  for (int row = 0; row < NUMROWS; row++) {
    for (int column = 0; column < NUMCOLS; column++) {
      g->grid[row][column] = 0;
    }
  }
}

void printgrid(Grid g)
{
  for (int row = 0; row < NUMROWS; row++) {
    for (int column = 0; column < NUMCOLS; column++) {
      printf("%d ", g->grid[row][column]);
    }
    printf("\n");
  }
}
