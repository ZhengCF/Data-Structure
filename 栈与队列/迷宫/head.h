#include"stdio.h"
#include"stdlib.h" 

#define size 		10
#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 

typedef int Maze;
typedef int Status;
typedef struct{
	int		x;
	int		y;
} posType;           //×ø±ê 

typedef struct{
	int     ord;
	posType seat;
	int     dir;
} SElemType;        //Õ»ÔªËØ

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
} Sqstack;
