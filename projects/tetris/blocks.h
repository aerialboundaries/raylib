#pragma once

#include "position.h"

/* 7種類のミノのID */

enum { I_BLOCK = 1, O_BLOCK, T_BLOCK, S_BLOCK, Z_BLOCK, J_BLOCK, L_BLOCK };

/* [4][4]の意味：4つの回転状態 × 4つのセルの座標 */
extern const Position block_shapes[8][4][4];
