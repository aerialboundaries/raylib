#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "block.h"
#include "colors.h"
#include "position.h"

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

struct block_type {
  int id;
  int cellSize;
  int rotaionState;
  Position pos;
  Color colors[MAX_COLOR];
};

Block create_block(void)
{
  Block b = malloc(sizeof(struct block_type));
  if (b == NULL)
    terminate("Error in create: grid could not be created.");
  memcpy(b->colors, colors, sizeof(colors));

  return b;
}
