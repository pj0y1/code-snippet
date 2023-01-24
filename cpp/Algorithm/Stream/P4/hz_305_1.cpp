// 方向数组
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

char mp[105][105];
int vis[105][105];
int dir[8][2] = {{0,1}, {1,0},{-1,0},{0,-1},
	{-1,1},{1,-1},{1,1},{-1,-1}
};
int n, m, sx, sy;

struct Point {
	int x, y;
};

void bfs(int sx, int sy){
	queue<Point> q;
	memset(vis, -1, sizeof vis);
	Point start = {sx, sy};
	q.push(start);
	vis[sx][sy] = 0;
	int ans = 0;
	while(!q.empty()){
		Point p = q.front();
		//printf("Point: %d %d\n", p.x, p.y);
		q.pop();
		for(int i=0; i<8; i++){
			int x = p.x + dir[i][0];
			int y = p.y + dir[i][1];
			if (x < 0 || x >= n || y < 0 || y >= m){
				continue;
			}
			if(mp[x][y] == '.' && vis[x][y] == -1){
				q.push(Point{x, y});
				vis[x][y] = vis[p.x][p.y]+1;
				ans = max(ans, vis[x][y]);
//				printf("@@@ %d %d %d\n", x, y, vis[x][y]);		
		
			}
		}
	}
	printf("%d\n", ans);
}



int main(){
	scanf("%d%d%d%d", &m, &n, &sy, &sx);
	sx--, sy--;
	for(int i = n-1; i >= 0; i--){
		scanf("%s", mp[i]);
	}
	
	bfs(sx, sy);
	return 0;
}
