#include <iostream>
// 判断'.'的连通性 找到最大连通区域
using namespace std;

int w, h, sx, sy;
char g[100][100];

int vis[100][100], ans;


int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y){
	vis[x][y] = 1;
		
	for(int i = 0; i < 4; i++){
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx < 1 || tx > h || ty < 1 || ty > w)
			continue;
		if(vis[tx][ty] || g[tx][ty] == '#')
			continue;
		dfs(tx, ty);
	}
	ans++;
}

int main(){
	cin >> w >> h;
	string line;
	for(int i = 1; i <= h; i++){
		cin >> line;
		for(int j = 1; j <= w; j++){
			if(line[j-1] == '@'){
				sx = i;
				sy = j;
				g[i][j] = '.';
			}else{
				g[i][j] = line[j-1];
			}
		}
	}
	dfs(sx, sy);
	cout << ans << endl;

	return 0;
}
