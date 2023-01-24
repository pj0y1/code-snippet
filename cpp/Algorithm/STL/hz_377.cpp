#include <stack>
#include <cstdio>

using namespace std;

char s[305];

int main(){
	stack<char> stk;
	scanf("%s", s);
	int i = 0;
	while(s[i] && s[i] != '@'){
		if(s[i] == '('){
			stk.push(s[i]);
		}else if(s[i] == ')'){
			if(!stk.empty() && stk.top() == '('){
				stk.pop();
			}else{
				printf("NO\n");
				return 0;
			}
		}
		i++;
	}
	if(!stk.empty())
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
