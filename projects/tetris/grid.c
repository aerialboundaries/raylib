#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
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
  int colors[MAX_COLOR];
};

Grid create(void)
{
  Grid g = malloc(sizeof(struct grid_type));
  if (g == NULL)
    terminate("Error in create: grid could not be created.");
  g->rows = NUMROWS;
  g->cols = NUMCOLS;
  g->cellSize = 30; // cell size for 300 x 600
  memcpy(g->colors, colors, sizeof(colors));

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

void Draw(Grid g)
{
  for (int row = 0; row < NUMROWS; row++) {
    for (int column = 0; column < NUMCOLS; column++) {
      int cellValue = g->grid[row][column];
      DrawRectangle(column * g->cellSize + 1, row * g->cellSize + 1,
                    g->cellSize - 1, g->cellSize - 1, colors[cellValue]);
    }
  }
}

void set_cell_value(Grid g, int row, int col, int value)
{
  g->grid[row][col] = value;
}
