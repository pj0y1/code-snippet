// ebay的面试问过的题 用的是二维的二分查找
// 暴力法 o(n*m)
// 更好的解法 从左下角或右上角出发 o(n+m)
#include <iostream>
#include <cstdio>
using namespace std;

int matrix[3005][3005];

int main(){
	int n, m, tmp;
	scanf("%d%d", &n, &m);
	for(int i = 0; i< n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	cin >> tmp;
	int x=n-1, y=0;
	while(x >= 0 && y<m){
		if (matrix[x][y] == tmp){
			printf("%d %d\n", x+1, y+1);
			return 0;
		} else if( matrix[x][y] > tmp){
			x--;
		} else{
			y++;
		}
	}
	return 0;
}
