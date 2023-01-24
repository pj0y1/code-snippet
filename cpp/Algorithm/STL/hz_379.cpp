#include <cstdio>
#include <stack>

using namespace std;

int n, act, tmp, ans;

int main(){
	stack<int> stk;
	stack<int> smax;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &act);
		switch(act){
			case 0: 
				{
					scanf("%d", &tmp);
					ans = !smax.empty()? max(smax.top(),tmp): tmp;
					stk.push(tmp);
					smax.push(ans);
				} break;
			case 1: 
				{ 
					if (!stk.empty()){
						//printf("pop stk %d\n", stk.top());
						//printf("pop smax %d\n", smax.top());
						stk.pop();
						smax.pop();
					}
				} break;
			case 2: 
				{
					if(!stk.empty()){
						printf("%d\n", smax.top());
					} else {
						printf("0\n");
					}
				} break;
		}
	}
	return 0;
}
