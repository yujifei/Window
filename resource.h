#ifndef FILE_RESOURCE_H
#define FILE_RESOURCE_H

static char * program_name = "开窗子";
static char * icon_file = "./icons/icon.png";
static char * logo_file = "./icons/logo.png";
static char * config_file = "./config/config";
static char * program_version = "1.0";

static char * win_message[] = 
{
	"哇！你真厉害！\n庾吉飞会为你感到骄傲的！",
	"当你赢了游戏的时候\n你应该意识到是游戏太简单而不是你太聪明！",
	"咦！你怎么又赢了\n真不知是你的幸运还是庾吉飞的不幸！",
	"编程者技艺低劣、鼠目寸光\n以至于你这么快就赢了！",
	"就一句话：你赢了！",
	"世界上有两种人：聪明人和玩这个游戏的人！",
	"你必须保持镇定，尽管这次你又赢了！",
	"历史是由赢家书写的......\n但赢得游戏并不能赋予你改写历史的权力！",
	"O_O你又赢了\n看来你的智商已经到庾吉飞的一半了！",
	"现在有一好一坏两个消息\n好消息是你赢了，坏消息是你接下来得玩一关更难的！",
	"当看到这个对话框时。乐观的玩家觉得通过了一关，\n悲观的玩家觉得开启了更难的关卡，而正真玩家会忽略这条信息！",
	"继续下一关还是退出游戏，你自己决定吧！"
};

#define MAX_WIN_MESSAGE_NUM 12

static char * help_message = 
	"\"开窗子\"是一种有利于智力的游戏，对玩家的唯一要求是\n"
	"其必须有操作鼠标的能力(我并没有歧视残疾人士的意思）。\n"
	"所有窗口(方格)有打开和关闭两个状态，关闭的窗口为红色，\n"
	"打开的窗口为蓝色。初始状态下，每个窗口为关闭。当某个窗口\n"
	"被单击时，其上、下、左、右的窗口(如果有)连同自己的状态\n"
	"会反转(即打开的窗子会关闭，关闭的窗子会打开)。当所有的\n"
	"窗子被打开时您就赢了。祝您好运。";

static char * about_message_copyright = "Copyright (C) 2007 - 2011 庾吉飞编写";
static char * about_message_comments  = "\"开窗子\"游戏适合高智商并具有良好空间想像力的人玩，低智商人士请自觉绕行！";
static char * about_message_website   = "blog.163.com/yujihui_xidian";

#endif
