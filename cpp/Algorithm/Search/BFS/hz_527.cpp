#include <iostream>
#include <queue>
using namespace std;

int n, m, d, mark[105][105][105];

char g[105][105];

int dir[4][2] = {0,1,1,0,0,-1,-1,0};

struct node {
	int x, y, step, d;
};


int main(){
	queue<node> que;
	cin >> n >> m >> d;
	for(int i = 1; i <= n; i++){
		cin >> &g[i][1];
	}
	
	que.push((node){1,1,0,d});
	mark[1][1][d] = 1;

	while(!que.empty()){
		node t = que.front();
		que.pop();
		for(int i = 0; i < 4; i++){
			for(int j = 2; j <= t.d; j++){
				int x = t.x + dir[i][0]*j;
				int y = t.y + dir[i][1]*j;
				if( x < 1 || y < 1 || x > n || y > m || g[x][y] == 'L')
					continue;
				if(x == n && y == m){
					cout << t.step+1 << endl;
					return 0;
				}
				if(mark[x][y][t.d-j] == 0){
					mark[x][y][t.d-j] =1;
					que.push((node){x, y, t.step+1, t.d - j});
				}
			
			}
			int x = t.x + dir[i][0];
			int y = t.y + dir[i][1];
			if(x == n && y == m){
				cout << t.step+1 << endl;
				return 0;
			}
			if( x < 1 || y < 1 || x > n || y > m || g[x][y] == 'L')
				continue;
			if(mark[x][y][t.d] == 0){
				mark[x][y][t.d] = 1;
				que.push((node){x, y, t.step+1, t.d});
			}

		}
	}
	cout << "impossible" << endl;


	return 0;
}
