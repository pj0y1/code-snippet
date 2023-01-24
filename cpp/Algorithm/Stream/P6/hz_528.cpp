#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, x, y, e[105][105], vis[105];

int main(){
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &e[i][j]);
		}
	}

	queue<int> q;
	q.push(x);
	memset(vis, -1, sizeof vis);
	vis[x] = 0;
	while(!q.empty()){
		int z = q.front();
		q.pop();
		if (z == y) break;
		for(int i = 1; i <= n; i++){
			if (vis[i] == -1 && e[z][i] == 1){
				q.push(i);
				vis[i] = vis[z] + 1;
			}
		}
	}
	if (vis[y] == -1){
		printf("%d\n", 0);
	}else{
		printf("%d\n", vis[y]-1);
	}
	return 0;
}
