#include <iostream>
#include <queue>
using namespace std;

int n, m, sx, sy;

char mmap[2005][2005];
int ans[2005][2005];

// 设置状态变量 按位保存状态
// 0 有无手机都没来过
// 1 没手机的时候来过
// 2 有手机的时候来过
// 3 有没手机都来过
struct node {
	int x, y, step, flag;
};

int dir[4][2] = {0,1,1,0,0,-1,-1,0};



int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mmap[i][j];
			if(mmap[i][j] == 'S'){
				sx = i, sy = j;
			}
		}
	}

	queue<node> que;
	que.push((node){sx, sy, 0, 0});
	ans[sy][sy] = 1;
	while(!que.empty()){
		node t = que.front();
		que.pop();
		for (int i = 0; i < 4; i++){
			int xx = t.x + dir[i][0];
			int yy = t.y + dir[i][1];
			if(xx < 1 || yy < 1 || xx > n || yy > m)
				continue;
			if(mmap[xx][yy] == '#')
				continue;
			// 没手机的时候已经来过
			if(t.flag == 0 && ((ans[xx][yy] & 1) != 0)){
				continue;
			}
			// 有手机的时候也已经来过
			if (t.flag == 1 && ((ans[xx][yy] & 2) != 0))
				continue;
			if(t.flag == 1 && mmap[xx][yy] == 'T') {
				cout << t.step + 1 << endl;
				return 0;
			}
			if(mmap[xx][yy] == 'S' || mmap[xx][yy] == 'T' || mmap[xx][yy] == '.'){
				que.push((node){xx, yy, t.step+1, t.flag});
				ans[xx][yy] += t.flag + 1;
			}
			if(mmap[xx][yy] == 'P'){
				que.push((node){xx, yy, t.step+1, 1});
				ans[xx][yy] = 3;
			}
		}
	}

	return 0;
}
