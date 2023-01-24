#include <iostream>
using namespace std;

char graph[135][135];
int n, m;

int main(){
	cin >> n >> m;
	for(int i = 0; i< n; i++){
		for(int j = 0; j<m; j++){
			cin >> graph[i][j];
		}
	}
	int t1, t2, t3, t4;
	while(1){
	
		cin >> t1 >> t2 >> t3 >> t4;
		if (t1 == 0 && t2 == 0 && t3 == 0 && t4 == 0){
			break;
		}

	}


	return 0;
}
