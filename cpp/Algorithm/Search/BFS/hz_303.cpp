#include <iostream>
#include <queue>
using namespace std;
// bfs 多起点搜索
// 最早到达0的1 会最快更新ans 因此无需func
int n, m, ans[1005][1005];
char mmap[1005][1005];

struct node{
	int x, y, step;
};

int dir[4][2] = {1,0,0,1,-1,0,0,-1};

void func(int x, int y){
	queue<node> que;
	ans[x][y] = 0;
	que.push((node){x, y,0});
	while(!que.empty()){
		node tmp = que.front();
//		cout << tmp.x << " " << tmp.y << endl;
		que.pop();
		for(int i =0; i < 4; i++){
			int xx = tmp.x + dir[i][0];
			int yy = tmp.y + dir[i][1];
			if(xx < 1 || yy < 1 || xx > n || yy > m)
				continue;
			if(mmap[xx][yy] == '0'){
				if (ans[xx][yy] == 0){
					ans[xx][yy] = tmp.step+1;
					que.push((node){xx, yy, tmp.step+1});
				}else if (ans[xx][yy] > tmp.step+1){
					// 这里会重复搜索 造成超时
					ans[xx][yy] = min(ans[xx][yy], tmp.step+1);
					que.push((node){xx, yy, ans[xx][yy]});
				}
			}
		}

	}
}



int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> &mmap[i][1];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mmap[i][j] == '1'){
				func(i, j);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(j > 1){
				cout << " ";
			}
			cout << ans[i][j];
		}
		cout << endl;
	}


	return 0;
}
