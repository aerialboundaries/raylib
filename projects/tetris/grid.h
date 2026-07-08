#pragma once
#include <raylib.h>

#define NUMROWS 20
#define NUMCOLS 10

typedef struct grid_type *Grid;

Grid create_grid(void);
void destroy_grid(Grid g);
void initialize_grid(Grid g);
void printgrid(Grid g);
void Draw(Grid g);
void set_cell_value(Grid g, int row, int col, int value);
int get_cell_value(Grid g, int row, int col);
