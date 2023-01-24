#include <iostream>

using namespace std;

/* n=1 边长1
 * n=2 3
 * n=3 9
 * F(n) = 3*F(n-1)
 *
 * 递归实现
 *
 */

char ans[1005][1005];
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};

void draw(int x, int y, int n){
	if(n == 1){
		ans[x][y] = 'X';
		return;
	}
	draw(x, y, n-1);
	draw(x, y+num[n]/3*2, n-1);
	draw(x + num[n]/3*2, y, n-1);
	draw(x+ num[n]/3, y+ num[n]/3, n-1);
	draw(x + num[n]/3*2, y+num[n]/3*2, n-1);
}
 


int main(){
	draw(1,1,7);
	int n;
	while(cin >> n){
		if(n == -1) break;
		for(int i = 1; i <= num[n]; i++){
			for(int j=1; j <= num[n]; j++){
				if(ans[i][j] == 'X'){
					cout << 'X';
				} else {
					cout << ' ';
				}
			}
			cout << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}
