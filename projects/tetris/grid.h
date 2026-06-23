#pragma once

#define NUMROWS 20
#define NUMCOLS 10

typedef struct grid_type *Grid;
typedef enum colors {
  darkGrey,
  green,
  red,
  orange,
  yellow,
  purple,
  cyan,
  blue,
  MAX_COLOR
} Colors;

Grid create(void);
void destroy(Grid g);
void initialize(Grid g);
void printgrid(Grid g);
