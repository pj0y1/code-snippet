// 预习课 小开的魔法机
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int *data;
    int top;
    int size;
}Stack;

Stack * initStack(int size){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int)*size);
    s->size = size;
    s->top = -1;
	return s;
}

void push(Stack *s, int val){
    s->top++;
    s->data[s->top] = val;
    return;
}

int pop(Stack *s){
    int r = s->data[s->top];
    s->top--;
    return r;
}

int top(Stack*s){
    return s->data[s->top];
}

int isEmpty(Stack *s){
    return (!s || s->top < 0);
}

void freeStack(Stack * s){
    if (!s)
        return;
    free(s->data);
    free(s);
    return ;
}

int main(){
    int n, x;
    scanf("%d", &n);
    Stack * s = initStack(n);
    int * data = (int*)malloc(sizeof(int)*n);
    memset(data, 0, sizeof(int)*n);
    for(int i = 0; i<n; i++){
        scanf("%d", data+i);
    }
    int j = n-1;
    for(int i = n-1; i>= 0; i--){
        if(isEmpty(s) || data[i] == top(s)+1){
            push(s, data[i]);

		} else if (!isEmpty(s) && data[i] > top(s)+1){
			data[j] = data[i];
			j--;
		}else{
			while(!isEmpty(s)){
				data[j] = pop(s);
				j--;
			}
			push(s, data[i]);
            
        }
    }
	while(!isEmpty(s)){
		data[j] = pop(s);
		j--;
	}
	int flag = 1;
    for(int i = 0; i<n; i++){
		if(data[i] != i+1){
			printf("NO\n");
			flag = 0;
			break;
		}
	}
	if(flag)
		printf("YES\n");
    freeStack(s);
    free(data);
    return 0;
}
