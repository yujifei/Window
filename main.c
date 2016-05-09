#include"global_init.h"
#include"gui.h"

int main(int argc, char * argv[])
{
	global_init();
	main_window(&argc, &argv);
	
	return 0;
}
