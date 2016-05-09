#include "game_logical.h"
#include "callback.h"
#include "global_init.h"
#include "config_op.h"
#include "gui.h"

void global_init()
{
	read_config(&num_grid, &win_width, &win_height);
	init_map();
	
	size_per_grid = 20.0;
	
	bgcolor[0] = 0.0, bgcolor[1] = 0.0, bgcolor[2] = 0.0;
	grid_color[0] = 1.0, grid_color[1] = 1.0, grid_color[2] = 1.0;
	wopn_color[0] = 0.0, wopn_color[1] = 0.0, wopn_color[2] = 1.0;
	wcls_color[0] = 1.0, wcls_color[1] = 0.0, wcls_color[2] = 0.0;
}
