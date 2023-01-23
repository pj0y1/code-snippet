#include <stdio.h>
#include <string.h>
#define MAX_LEN 10000


char input[MAX_LEN+5] = {0};
char stack[MAX_LEN+5] = {0};

int main(){
	scanf("%s", input);
	int len = strlen(input);
	int top = -1;
	for(int i = 0; i <= len; i++){
		char c = input[i];
		switch(c){
			case '(':
			case '[': 
			case '{':
				stack[++top] = c; 
				break;
			case '}':
				if(top < 0 || stack[top] != '{'){
					printf("NO\n");
					return 0;
				} else {
					top--;
				}
				break;
			case ']': 
				if(top < 0 || stack[top] != '['){
					printf("NO\n");
					return 0;
				} else {
					top--;
				}
				break;
			case ')': 
				if(top < 0 || stack[top] != '('){
					printf("NO\n");
					return 0;
				} else {
					top--;
				}
				break;
		}
	}
	if (top >= 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
