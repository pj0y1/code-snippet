#include <iostream>

using namespace std;

int t;

bool hasT(int n){
	while(n){
		if(n%10 == t)
			return true;
		n /= 10;
	}
	return false;
}

int main(){
	int m, cnt=0;
	cin >> m >> t;
	for(int i = 1; i <= m; i++){
		if(hasT(i)){
			continue;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
