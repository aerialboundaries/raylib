#pragma once
#include "position.h"

typedef struct block_type *Block;

Block create_block(int id);
void destroy_block(Block b);
void draw_block(Block b);
void Move(Block b, int rows, int columns);
void GetCellPositions(Block b, Position movedTiles[4]);
