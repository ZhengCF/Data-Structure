#include"basic.h"
#define CHUNKSIZE 80

typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk *next;
}Chunk;

typedef struct{
	Chunk *head ,*rear;
	int curlen; 
}LString;


