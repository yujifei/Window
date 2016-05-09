/* Copyright (C) yujihui 2011-1-22
 * file game_logical.h 
 * 包含与游戏逻辑相关的函数与数据
 * 实际上游戏逻辑相当简单
 */

#ifndef FILE_GAME_LOGICAL_H
#define FILE_GAME_LOGICAL_H

#include<gtk/gtk.h>

#define MAX_GRID_NUM  36
#define MIN_GRID_NUM  2

unsigned int num_grid;

unsigned char map[MAX_GRID_NUM * MAX_GRID_NUM];

void init_map();
void update_map(int r, int c);
gboolean judge_win();
void do_win();

#endif
