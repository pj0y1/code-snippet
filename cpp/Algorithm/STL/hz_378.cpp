#include<cstdio>
#include<stack>

using namespace std;

char s[305];

int main(){
	stack<char> stk;
	scanf("%s", s);
	int i=0;
	while(s[i] && s[i] != '@'){
		switch(s[i]){
			case '(':
			case '[':
			case '{':
				stk.push(s[i]); break;
			case ')':
				{	if(!stk.empty() && stk.top() == '(') stk.pop(); 
					else {printf("NO\n"); return 0;}
				}break;
			case ']':
				{	if(!stk.empty() && stk.top() == '[') stk.pop(); 
					else {printf("NO\n"); return 0;}
				}break;
			case '}':
				{	if(!stk.empty() && stk.top() == '{') stk.pop(); 
					else {printf("NO\n"); return 0;}
				}break;
			default:
				break;

		}
		i++;
	}
	if(stk.empty()){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}
