#include <cstdio>
#include <stack>

using namespace std;

/* 溶液 = 溶剂 + 溶质
 * 溶液的质量 = 溶剂的质量 + 溶质的质量
 * 溶液的浓度 = 溶质的质量 / (溶液的质量)
 * 盐水: 溶剂为水 溶质为氯化钠
 *
 * 所以这道题 要追踪溶质的质量变化
 *
 * */

int n;
double c, ci, v, vi;
char act;

struct node {
	double v;
	double c;
};

int main(){
	scanf("%lf %lf %d", &v, &c, &n);
	stack<node> stk;
	stk.push((node){v, c});
	while(~scanf("%c", &act)){
		if(act == 'P'){
			scanf("%lf %lf", &vi, &ci);
			double total_mess = stk.top().v + vi;
			double total_salt = stk.top().v * stk.top().c/100 + ci * vi/100;
			stk.push((node){total_mess, total_salt*100/total_mess});
			printf("%d %.5lf\n", (int)stk.top().v, stk.top().c);
		}else if (act == 'Z'){
			if(stk.size() > 1) {
				stk.pop();
			}
			printf("%d %.5lf\n", (int)stk.top().v, stk.top().c);
		}
	}
	return 0;
}

