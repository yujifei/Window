#include<stdio.h>
#include<stdlib.h>
#include "config_op.h"
#include "resource.h"

void read_config(int * grad_num, int * win_width, int * win_height)
{
	FILE * fp = fopen(config_file, "r");
	if(fp == NULL)
	{
		printf("fatal error, cannot open file %s\n", config_file);
		exit(1);
	}
	
	fscanf(fp, "%d %d %d", grad_num, win_width, win_height);
	
	fclose(fp);
}

void write_config(int grad_num, int win_width, int win_height)
{
	FILE * fp = fopen(config_file, "w+");
	
	if(fp == NULL)
	{
		printf("fatal error, cannot open file %s\n", config_file);
		exit(1);
	}
	
	fprintf(fp, "%d %d %d", grad_num, win_width, win_height);
	
	fclose(fp);
}
