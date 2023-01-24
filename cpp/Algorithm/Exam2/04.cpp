#include<iostream>
#include<queue>
using namespace std;

int n, m, sx, sy, ex, ey, mark[2005][2005], vis[2005][2005];

struct node {
	int x, y, step;
};

char g[2005][2005];

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int findMaxStep(int x, int y, int dirIdx){
	int cnt = 1;
	int dx = dir[dirIdx][0];
	int dy = dir[dirIdx][1];
	while( x + cnt *dx > 0 && x + cnt * dx <= n && y + cnt *dy > 0 && y+cnt*dy <= m && g[x+cnt*dx][y+cnt*dy] == '.'){
		cnt++;
	}
	return cnt - 1;
}

int findSpecialStep(int x, int y, int dirIdx){
	int cnt = 1;
	int obj = 0;
	int dx = dir[dirIdx][0];
	int dy = dir[dirIdx][1];
	while( x + cnt *dx > 0 && x + cnt * dx <= n && y + cnt *dy > 0 && y+cnt*dy <= m){
		if(g[x+cnt*dx][y+cnt*dy] == 'o'){
			obj ++;
		}
		if(obj == 2){
			break;
		}
		cnt++;
	}
	if(obj == 2){
		return cnt;
	}
	return 0;
}




int main(){
	cin >> n >> m;
	for(int i = 1; i<= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> g[i][j];
			if(g[i][j] == 'x'){
				sx = i, sy = j;
			}
			if(g[i][j] == 'o'){
				mark[i][j] = 1;
			}
		}
	}
	cin >> ex >> ey;

	queue<node> que;
	que.push((node){sx, sy, 0});
	vis[sx][sy] = 1;
	while(!que.empty()){
		node t = que.front();
//		cout << t.x << " " << t.y << " " << t.step << endl;
		que.pop();
		if(t.x == ex && t.y == ey){
			cout << t.step << endl;
			return 0;
		}
		for(int i = 0; i < 4; i++){
			int cnt = findMaxStep(t.x, t.y, i);
			for(int j = 1; j <= cnt; j++){
				if(vis[t.x+j*dir[i][0]][t.y+j*dir[i][1]] == 0){
					vis[t.x+j*dir[i][0]][t.y+j*dir[i][1]] = 1;
					que.push((node){t.x + j * dir[i][0], t.y + j * dir[i][1], t.step+1});
					
				}
			}
			int spec = findSpecialStep(t.x, t.y, i);
			if(spec > 0){
				if(vis[t.x+spec*dir[i][0]][t.y+spec*dir[i][1]] == 0){
					vis[t.x+spec*dir[i][0]][t.y+spec*dir[i][1]] = 1;
					que.push((node){t.x + spec * dir[i][0], t.y + spec * dir[i][1], t.step+1});
					
				}
				
			}
		}
	}

	return 0;
}
