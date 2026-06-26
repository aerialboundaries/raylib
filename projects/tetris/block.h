#pragma once

#include "colors.h"
#include "position.h"

typedef struct block_type *Block;

Block create_block(void);
void destroy_block(Block b);
void initialize_block(Block b);
