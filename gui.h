#ifndef FILE_GUI_H
#define FILE_GUI_H

#include<gtk/gtk.h>
#include "game_logical.h"

int win_width, win_height;

GtkWidget * size_menu_items[MAX_GRID_NUM - MIN_GRID_NUM + 1];

GtkWidget * create_menu(void);
void main_window(int * argc, char ** argv[]);
void show_win_dlg();

#endif
