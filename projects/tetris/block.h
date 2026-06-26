#pragma once

#include "colors.h"
#include "position.h"

typedef struct block_type *Block;

Block create_block(int id);
void destroy_block(Block b);
void draw_block(Block b);
