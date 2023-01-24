#include <iostream>

using namespace std;

int n, m, sx, sy, ans=1;
char mmap[3005][3005];
int vis[3005][3005];

int dir[4][2] = {1,0,0,1,-1,0,0,-1};

void func(int x, int y){
	for(int i = 0; i < 4; i++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(xx < 1 || xx > n || yy < 1 || yy > m)
			continue;
		if(vis[xx][yy]==0 && mmap[xx][yy] + mmap[x][y]-'0'-'0' == 1){
			vis[xx][yy] = 1;
			ans++;
			func(xx, yy);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> &mmap[i][1];
	}
	cin >> sx >> sy;
	vis[sx][sy] = 1;
	func(sx, sy);
	cout << ans << endl;
	return 0;
}
