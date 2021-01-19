#include"stdio.h"
#include"stdlib.h" 

#define size 		10
#define TRUE    	 1
#define FLASE   	 0
#define OK      	 1
#define ERROR   	 0
#define INFEASIBLE  -1
#define OVERFLOW    -2 

typedef int Status;

typedef struct {
	int Occurtime;
	int Ntype;            //0 is arrivel,1 to 4 meas quit event of 4 windows;
}Event,ElemType;

typedef struct {
	int ArrivalTime;
	int Duration;
	int num;
}QElemType;              //data type of queue;
