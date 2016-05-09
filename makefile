CC 		= gcc
cflags  = `pkg-config --cflags gtk+-2.0`
lflags  = `pkg-config --libs gtk+-2.0`
preflag = -g -Wall

clbck_dep = callback.c callback.h
gui_dep = gui.c gui.h resource.h
init_dep = global_init.c global_init.h
game_dep = game_logical.c game_logical.h
main_dep = main.c
config_dep = config_op.h config_op.c

target = window
target_dep = callback.o gui.o global_init.o game_logical.o main.o config_op.o

$(target):$(target_dep)
	$(CC) $(preflag) $(target_dep) -o $(target) $(lflags)
	
callback.o:$(clbck_dep)
	$(CC) $(preflag) -c $(clbck_dep) $(cflags)
	
gui.o:$(gui_dep)
	$(CC) $(preflag) -c $(gui_dep) $(cflags)
	
global_init.o:$(init_dep)
	$(CC) $(preflag) -c $(init_dep) $(cflags)
	
game_logical.o:$(game_dep)
	$(CC) $(preflag) -c $(game_dep) $(cflags)
	
config_op.o:$(config_op)
	$(CC) $(preflag) -c $(config_dep) $(cflags)
	
main.o:$(main_dep)
	$(CC) $(preflag) -c $(main_dep) $(cflags)


clean:
	rm -f *.gch	
