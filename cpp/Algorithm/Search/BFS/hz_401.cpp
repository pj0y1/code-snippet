#include <iostream>
#include <queue>
using namespace std;

// bfs 从(x,y)到(1,1)和从(1,1)到(x,y)的步数一样
// 先func(1,1)把所有答案计算好
int n, x, y;

int ans[505][505];

struct node {
	int x, y, step;
};

int dir[12][2] = {
	1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,-1,-2,1,
	2,2,2,-2,-2,2,-2,-2
};


int main(){
	queue<node> que;
	que.push((node){1,1,0});
	while(!que.empty()){
		node tmp = que.front();
		que.pop();
		for(int i = 0; i < 12; i++){
			int xx = tmp.x + dir[i][0];
			int yy = tmp.y + dir[i][1];
			if( xx < 1 || yy < 1 || xx > 500 || yy > 500)
				continue;
			if(ans[xx][yy] == 0 && (xx != 1 || yy != 1)){
				ans[xx][yy] = tmp.step+1;
				que.push((node){xx, yy, tmp.step+1});
			}
		}
	}


	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		cout << ans[x][y] << endl;
	}
	

	return 0;
}
