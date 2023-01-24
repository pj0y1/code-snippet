#include <iostream>

using namespace std;

// n的全排列

int n, used[15], num[15];

void func(int idx){
	if(idx == n){
		for(int i = 0; i < n; i++){
			if(i)
				cout << " ";
			cout << num[i];
		}
		cout << endl;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(used[i] == 0){
			used[i] = 1;
			num[idx] = i;
			func(idx+1);
			used[i] = 0;
		}
	}
}


int main(){
	cin >> n;
	func(0);
	return 0;
}
