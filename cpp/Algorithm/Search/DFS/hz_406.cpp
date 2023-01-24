#include <iostream>
using namespace std;

int n, m, ans;

char g[2005][2005];

struct node {
	int x, y;
};

int dir[8][2] = {0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};


void func(int x, int y){
	for(int i = 0 ;i < 8; i++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(g[xx][yy] == '#'){
			g[xx][yy] = '.';
			func(xx, yy);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> &g[i][1];
	}
	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == '#'){
				ans++;
				g[i][j] = '.';
				func(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
