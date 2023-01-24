#include <iostream>
#include <stack>
using namespace std;

int n, m, k;

int dir[4][2] = {1,0,0,1,-1,0,0,-1};
char g[3005][3005];
int vis[3005][3005];

struct node {
	int x, y;
};

stack<node> stk;

void func(int x, int y){
	for(int i = 0; i < 4; i++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(xx < 1 || xx > n || yy < 1 || yy > m)
			continue;
		if(vis[xx][yy] == 0 && g[xx][yy] != g[x][y]){
			vis[xx][yy] = 1;
			stk.push((node){xx,yy});
			func(xx, yy);
		}

	}
}


int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> &g[i][1];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(vis[i][j] == 0){
				vis[i][j] = 1;
				stk.push((node){i,j});
				func(i, j);
				int cnt = stk.size();
				while(!stk.empty()){
					node tmp = stk.top();
					stk.pop();
					vis[tmp.x][tmp.y] = cnt;
				}
			}
		}
	}

	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		cout << vis[x][y] << endl;
	}
	return 0;
}
