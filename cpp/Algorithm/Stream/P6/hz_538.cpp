#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/* 
 *
 * */
int e[25][25], vis[25], n;


void dfs(int x){
	if(x != 1){printf("-");}
	printf("%d", x);
	for(int i = 1; i <= n; i ++){
		if(vis[i] == 0 && e[x][i] == 1){
			vis[i] = 1;
			dfs(i);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &e[i][j]);
		}
	}
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++){
		if (vis[i] == 0){
			vis[i] = 1;
			dfs(i);
		}
	}
	printf("\n");
	return 0;
}
