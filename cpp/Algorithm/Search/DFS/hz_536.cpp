#include <iostream>

using namespace std;

int n, m, ans, tmp;

char g[105][105];

int dir[4][2] = {1,0,0,1,-1,0,0,-1};

void func(int x, int y){
	for(int i = 0; i < 4; i++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(xx < 1 || xx > n || yy < 1 || yy > m)
			continue;
		if (g[xx][yy] == '1'){
			tmp++;
			g[xx][yy] = '0';
			func(xx, yy);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> &g[i][1];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == '1'){
				tmp = 1;
				g[i][j] = '0';
				func(i, j);
				ans = max(ans, tmp);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
