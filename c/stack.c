#include <stdio.h>
#include<stdlib.h>

typedef struct Stack {
	int * data;
	int top;
	int size;
} Stack;


Stack * initStack(int size){
	Stack * s = (Stack *)malloc(sizeof(Stack));
	s->data = (int *)malloc(sizeof(int)*size);
	s->top = -1;
	s->size = size;
	return s;
}

void freeStack(Stack * s){
	if(!s) 
		return;
	free(s->data);
	free(s);
	return; // todo 这样其实不太好
}
