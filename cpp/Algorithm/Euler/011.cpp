#include <iostream>

using namespace std;

int graph[28][28];

typedef struct Direction {
	int x, y;
} Direction;
// ans : 70600674
Direction dir[4] = {{0, -1},{-1,0},{-1,-1},{1,-1}};

int main(){
	int ans = 0, tmp;
	for(int i=4; i<24; i++){
		for(int j=4; j<24; j++){
			 cin >> graph[i][j];
		}
	}
	for( int i=4; i < 24; i++){
		for(int j=4; j < 24; j++){
			for(int k=0; k < 4; k++){
				tmp = 1;
				Direction d = dir[k];
				for (int u = 0; u < 4; u++){
					tmp *= graph[i+u*d.x][j+u*d.y];
				}
			}
			ans = ans > tmp? ans:tmp;
		}
	}
	cout << ans << endl;
	return 0;
}
