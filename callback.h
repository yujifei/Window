/* Copyright (C) yujihui 2011-1-22
 * callback.h 所有回调函数的声明
 */
 
#ifndef FILE_CALLBACK_H
#define FILE_CALLBACK_H

#include<gtk/gtk.h>

GtkWidget * DrawArea;

double size_per_grid;
double bgcolor[3]; //背景色
double grid_color[3]; //栅格颜色
double wcls_color[3]; //打开"窗子"颜色
double wopn_color[3]; //关闭"窗子"颜色

double FrameData[3]; //用于回调函数间传递数据

void on_program_exit(GtkWidget * widget, gpointer data); //程序退出
gboolean on_configure(GtkWidget * widget, GdkEventConfigure * event, gpointer data); //窗口的configure-event
gboolean on_expose(GtkWidget * widget, GdkEventExpose * event, gpointer data);		 //窗口的expose-event
gboolean on_menu_new_game_clicked(GtkWidget * item, gpointer data); // 菜单 文件 -> 新建 单击
gboolean on_menu_restart_game_clicked(GtkWidget * item, gpointer data); // 菜单 文件 -> 重启 单击
gboolean on_help_about_clicked(GtkWidget * item, gpointer data); // 帮助 -> 关于 菜单项 单击事件
gboolean on_help_thanks_clicked(GtkWidget * item, gpointer data); //帮助 -> 致谢 菜单项 单击事件
gboolean on_setting_size_clicked(GtkWidget * item, gpointer data); //菜单 size子菜单n x n clicked
gboolean on_clicked(GtkWidget * widget, GdkEventButton * event, gpointer data); //游戏过程的单击事件


#endif
