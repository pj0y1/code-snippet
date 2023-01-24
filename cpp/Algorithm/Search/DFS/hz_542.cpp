#include <iostream>
#include <cmath>
#include <cstring>
/* 用到了邻接矩阵 标记数组 dfs
 * */
using namespace std;


int t, n, h, r, ball[1005][3], start[1005], stop[1005], start_cnt;

int conn[1005][1005], mark[1005];


int func(int x){
	if(stop[x] == 1){
		return 1;
	}
	for(int i = 0; i < n; i++){
		if(mark[i] == 0 && conn[x][i] == 1){
			mark[i] = 1;
			if (func(i)){
				return 1;
			}
		}
	}
	return 0;
}


int main(){
	cin >> t;
	for(int k = 0; k < t; k++){
		start_cnt = 0;
		memset(stop, 0, sizeof(stop));
		memset(mark, 0, sizeof(mark));
		memset(conn, 0, sizeof(conn));
		cin >> n >> h >> r;
		for(int i = 0; i < n; i++){
			for(int j = 0 ; j < 3; j++){
				cin >> ball[i][j];
			}
			if(ball[i][2] <= r ){
				start[start_cnt] = i;
				start_cnt++;
			}
			if (ball[i][2] >= h-r){
				stop[i] = 1;
			}
			for(int j = 0; j < i; j++){
				long long t1 = ball[i][0] - ball[j][0];
				long long t2 = ball[i][1] - ball[j][1];
				long long t3 = ball[i][2] - ball[j][2];
				double dis = sqrt(t1*t1 + t2*t2 + t3*t3);
				if(dis <= 2 * r){
					conn[i][j] = conn[j][i] = 1;
				}
			}
		}
		int flag = 0;
		for(int i = 0; i < start_cnt; i++){
			if(mark[start[i]] == 0){
				mark[start[i]] = 1;
				if (func(start[i])){
					cout << "Yes" << endl;
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0)
			cout << "No" << endl;
	}

	return 0;
}
