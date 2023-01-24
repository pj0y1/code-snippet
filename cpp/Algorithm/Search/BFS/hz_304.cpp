#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, sx, sy, ans;

char g[200][200];
int vis[200][200];

int dir[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-2,-1},{-1,-2}};

struct point {
	int x, y;
};

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m ; i ++){
		string line;
		cin >> line;
		for(int j = 1; j <= n; j++){
			g[i][j] = line[j-1];
			if(g[i][j] == 'K'){
				sx = i;
				sy = j;
			}
		}
		
	}
	queue<point> q;
	q.push((point){sx, sy});
	vis[sx][sy] = 1;
	bool hit = false;
	while(!hit && !q.empty()){
		int len = (int)q.size();
		ans += 1;
		for(int j = 0; j < len && !hit; j++){
			point p = q.front();
			for(int i = 0; i < 8; i++){
				int tx = p.x + dir[i][0];
				int ty = p.y + dir[i][1];
				if(tx < 1 || tx > m || ty < 1 || ty > n)
					continue;
				if(vis[tx][ty])
					continue;
				if(g[tx][ty] == '*')
					continue;
				if(g[tx][ty] == 'H'){
					hit = true;
					break;
				}
				vis[tx][ty] = 1;
				q.push((point){tx, ty});
			}
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}
