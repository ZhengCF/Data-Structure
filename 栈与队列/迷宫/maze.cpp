#include"head.h"

Maze maze[size][size]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}};


Status IniteStack(Sqstack &S){
	S.base=(SElemType *)malloc(100*sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=100;
	return 0;
} //IniteStack

Status GetTop(Sqstack S,SElemType e){
	if(S.base==S.top) return ERROR; 
	e=*(S.top-1);
	return OK;
} //GetTop

Status Push(Sqstack &S,SElemType e){
	if(S.top-S.base==S.stacksize){
		S.base=(SElemType *)realloc(S.base,(S.stacksize+10)*sizeof(SElemType));
		if(!S.base) exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=10;
	}
	*S.top++=e;
	return OK;
} //Push

Status Pop(Sqstack &S,SElemType &e){
	if(S.top==S.base) return ERROR;
	e=*--S.top;
	return OK;
} //Pop

Status elemValue(SElemType &e,int ord1,posType seat1,int dir1){
	e.ord=ord1;
	e.seat=seat1;
	e.dir=dir1;
	return 0;
}

Status posiValue(posType &seat,int x1,int y1){
	seat.x=x1;
	seat.y=y1;
	return 0;
}


int doMaze(Sqstack &S){
	SElemType e;
	posType seat;
	int dir=0;        //down=0,right=1,up=2,left=3;
	int i=1,x=1,y=1;
	IniteStack(S);
	posiValue(seat,x++,y);
	elemValue(e,i++,seat,dir);
	Push(S,e);
	while((x-1)!=(size-2)||y!=(size-2)){
		if(maze[x][y]==0){
			//go down
			dir=0;
			posiValue(seat,x++,y);
			elemValue(e,i++,seat,dir);
			Push(S,e);
		}
		else if(maze[--x][++y]==0){
			//go to right;
			(*(S.top-1)).dir=1; 
			posiValue(seat,x++,y);
			elemValue(e,i++,seat,dir);
			Push(S,e);
		}
		else {
			//go back 
			Pop(S,e);x--;i--;
			while(maze[x][y]!=0){
				Pop(S,e);x--;i--;
			}
			(*(S.top-1)).dir=1;
			dir=0;
			posiValue(seat,x++,y);
			elemValue(e,i++,seat,dir);
			Push(S,e);
		}
		
	}
	return OK;
}

void printMaze(){
	int i,j;
	//int m[size][size];
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(maze[i][j]==0)
				printf("  ");
			else if(maze[i][j]==1)
				printf("+ ");
			else printf("* ");
		}
		printf("\n");
	}
}

void printPath(Sqstack S){
	SElemType e;
	int i;
	printf("It's %d steps!\n",(*(S.top-1)).ord);
	for(i=0;i<(*(S.top-1)).ord;i++){
		e=*S.base++;
		printf("ord %d, position is :(%d,%d),the dirction of go on is :",e.ord,e.seat.x,e.seat.y);
		if(e.dir==0)
			printf("down;\n");
		else
			printf("right;\n"); 
	}
}

int main(){
	Sqstack S;
	doMaze(S);
	printMaze();
	printPath(S);	
}
