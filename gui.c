#include<gtk/gtk.h>
#include<stdlib.h>
#include<time.h>
#include "game_logical.h"
#include "callback.h"
#include "gui.h"
#include "resource.h"

void show_win_dlg()
{
	GtkWidget *dialog;
	int msg_idx;
	gchar * info;
	
	srand(time(0));
	msg_idx = rand() % MAX_WIN_MESSAGE_NUM;
	info = win_message[msg_idx];
	
	dialog = gtk_message_dialog_new(NULL, 
		 GTK_DIALOG_DESTROY_WITH_PARENT,
		 GTK_MESSAGE_INFO,
		 GTK_BUTTONS_OK, info, "title");
	gtk_window_set_title(GTK_WINDOW(dialog), "完成");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

GtkWidget * create_menu(void)
{
	GtkWidget * menubar;
	GtkWidget * menu;
	GtkWidget * menu_item;
	GtkWidget * sub_menu_item;
	
	menubar = gtk_menu_bar_new();
	
	//文件菜单
	menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_mnemonic("文件(_F)");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	
	sub_menu_item = gtk_menu_item_new_with_mnemonic("新建(_N)");
	gtk_signal_connect(GTK_OBJECT(sub_menu_item), "activate", G_CALLBACK(on_menu_new_game_clicked), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), sub_menu_item);
	
	sub_menu_item = gtk_menu_item_new_with_mnemonic("重启(_R)");
	gtk_signal_connect(GTK_OBJECT(sub_menu_item), "activate", G_CALLBACK(on_menu_restart_game_clicked), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), sub_menu_item);
	
	sub_menu_item = gtk_separator_menu_item_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), sub_menu_item);
	
	sub_menu_item = gtk_menu_item_new_with_mnemonic("退出(_Q)");
	gtk_signal_connect(GTK_OBJECT(sub_menu_item), "activate", G_CALLBACK(on_program_exit), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), sub_menu_item);
	
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);
	
	//设置菜单
	menu_item = gtk_menu_item_new_with_mnemonic("大小(_Z)");
	menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	char tmpbuf[7];
	int i;
	for(i = 0; i < MAX_GRID_NUM - MIN_GRID_NUM + 1; ++i)
	{
		sprintf(tmpbuf, "%d x %d", i + MIN_GRID_NUM, i + MIN_GRID_NUM);
		sub_menu_item = gtk_menu_item_new_with_label(tmpbuf);
		
		size_menu_items[i] = sub_menu_item;
		
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), sub_menu_item);
		gtk_signal_connect(GTK_OBJECT(sub_menu_item), "activate", G_CALLBACK(on_setting_size_clicked), (gpointer)(i + MIN_GRID_NUM));
	}
	menu = gtk_menu_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	menu_item = gtk_menu_item_new_with_mnemonic("设置(_S)");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);
	
	//帮助菜单
	menu = gtk_menu_new();
	menu_item = gtk_menu_item_new_with_mnemonic("帮助(_H)");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
	
	sub_menu_item = gtk_menu_item_new_with_mnemonic("关于(_A)");
	gtk_signal_connect(GTK_OBJECT(sub_menu_item), "activate", G_CALLBACK(on_help_about_clicked), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), sub_menu_item);
	
	sub_menu_item = gtk_menu_item_new_with_mnemonic("致谢(_T)");
	gtk_signal_connect(GTK_OBJECT(sub_menu_item), "activate", G_CALLBACK(on_help_thanks_clicked), NULL);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), sub_menu_item);
	
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menu_item);
	
	return menubar;
}

void main_window(int * argc, char ** argv[])
{
	GtkWidget * window;
	GtkWidget * vbox;
	GtkWidget * draw_area;
	GtkWidget * menu;
	
	gtk_init(argc, argv);
	init_map();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_default_size(GTK_WINDOW(window), win_width, win_height);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(window), program_name);
	gtk_window_set_icon_from_file(GTK_WINDOW(window), icon_file, NULL);
	
	vbox = gtk_vbox_new(FALSE, 0);
	draw_area = gtk_drawing_area_new();
	DrawArea = draw_area;
	gtk_drawing_area_size(GTK_DRAWING_AREA (draw_area), 200, 200);
	
	menu = create_menu();
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_pack_start(GTK_BOX(vbox), menu, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), draw_area, TRUE, TRUE, 0);
	
	gtk_widget_add_events(draw_area, GDK_BUTTON_PRESS_MASK);
	gtk_signal_connect(GTK_OBJECT(draw_area), "button-press-event", G_CALLBACK(on_clicked), (gpointer)FrameData);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(on_program_exit), NULL);
	gtk_signal_connect(GTK_OBJECT(draw_area), "expose-event", G_CALLBACK(on_expose), (gpointer)FrameData);
	gtk_signal_connect(GTK_OBJECT(draw_area), "configure-event", G_CALLBACK(on_configure), NULL);
	
	gtk_widget_show_all(window);
	gtk_main();
}
