#include<gtk/gtk.h>
#include<string.h>
#include"game_logical.h"

void init_map()
{
	memset(map, 0, sizeof(map));
}

void update_map(int r, int c)
{
	if(r < num_grid && c < num_grid)
	{
		map[r * num_grid + c] ^= 1;
		if(r + 1 < num_grid)
		{
			map[(r  + 1)* num_grid + c] ^= 1;
		}
		if(r - 1 >= 0)
		{
			map[(r  - 1)* num_grid + c] ^= 1;
		}
		if(c + 1 < num_grid)
		{
			map[r * num_grid + c + 1] ^= 1;
		}
		if(c - 1 >= 0)
		{
			map[r * num_grid + c - 1] ^= 1;
		}
	}
}

gboolean judge_win()
{
	int i = 0;
	gboolean res = TRUE;
	int grid_count = num_grid * num_grid;
	for(i = 0; i < grid_count; i++)
	{
		if(map[i] == 0)
		{
			res = FALSE;
			break;
		}
	}
	return res;
}

void do_win()
{
	init_map();
	if(num_grid < MAX_GRID_NUM )
	{
		++num_grid;
	}
	else
	{
		num_grid = MIN_GRID_NUM ;
	}
}
