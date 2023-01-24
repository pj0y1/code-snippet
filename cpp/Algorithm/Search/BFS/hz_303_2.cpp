#include <iostream>
#include <queue>
using namespace std;

int n, m, ans[1005][1005];
char mmap[1005][1005];

struct node{
	int x, y, step;
};

int dir[4][2] = {1,0,0,1,-1,0,0,-1};

int main(){
	queue<node> que;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mmap[i][j];
			if (mmap[i][j] == '1'){
				que.push((node){i,j,0});
			}
		}
	}

	while(!que.empty()){
		node t = que.front();
		que.pop();
		for(int i =0; i< 4; i++){
			int xx = t.x +dir[i][0];
			int yy = t.y +dir[i][1];
		
			if(ans[xx][yy] == 0 && mmap[xx][yy] == '0'){
				ans[xx][yy] = t.step+1;
				que.push((node){xx, yy, ans[xx][yy]});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(j > 1)
				cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
