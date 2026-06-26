#pragma once
#include <raylib.h>

#define NUMROWS 20
#define NUMCOLS 10

typedef struct grid_type *Grid;

Grid create(void);
void destroy(Grid g);
void initialize(Grid g);
void printgrid(Grid g);
void Draw(Grid g);
void set_cell_value(Grid g, int row, int col, int value);
