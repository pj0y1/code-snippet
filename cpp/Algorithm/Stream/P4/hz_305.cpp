#include <iostream>
#include <queue>

using namespace std;

int graph[105][105];
int x, y, mx, my;
char c;

int main(){
	cin >> x >> y >> mx >> my;
	for(int i = 1 ;i <= x; i++){
		for(int j=1; j <= y; j++){
			cin >> c;
			if (c == '*'){
				graph[i][j] = -1;
			}
		}
	}
	queue<pair<int,int>> q;
	q.push({mx, my});
	while(!q.empty()){
		pair<int, int> p = q.pop();

	}

	

	return 0;
}
