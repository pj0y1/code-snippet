#include <iostream>
#include <algorithm>
#include <cstdio>
// 优先完成罚款多的任务 并且用靠后的时间完成 并标记当前时间被占利用标记数组
using namespace std;

int money, n, mark[505];

struct node {
	int ddl, num;
};

node task[505];

bool cmp(const node &a, const node&b){
	if (a.num == b.num){
		return a.ddl < b.ddl;
	}
	return a.num > b.num;
}

int main(){
	scanf("%d %d", &money, &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &task[i].ddl);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &task[i].num);
	}
	sort(task, task+n, cmp);
	for(int i = 0; i < n; i++){
		for(int j=task[i].ddl; j > 0; j--){
			if(mark[j] == 0){
				mark[j] = 1;
				break;
			}
			if(j == 1) {
				money -= task[i].num;
			}
		}
	}
	printf("%d\n", money);
	return 0;
}
