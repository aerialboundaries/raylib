#pragma once

#include <raylib.h>
#include <stdbool.h>

typedef struct game_type *Game;

Game create_game(void);
void destroy_game(Game game);
void game_draw(Game game);
void game_handle_input(Game game);

// ブロックを1マス下に移動させる。実際に移動できた場合はtrue、
// 接地していて移動できなかった場合はfalseを返す。
bool game_move_block_down(Game game);

// 毎フレーム呼び出す。ロック猶予タイマーを監視し、
// 猶予時間が過ぎたブロックを固定（ロック）する。
void game_update(Game game);

// Getters to refer game over or scores from external
bool game_is_over(Game game);
int game_get_score(Game game);
Music game_get_music(Game game);
