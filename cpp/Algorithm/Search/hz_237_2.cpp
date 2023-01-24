#include <iostream>

using namespace std;

// n的全排列

int n, idx, used[15], num[15];

void func(){
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
			idx++;
			func();
			idx--;
			used[i] = 0;
		}
	}
}


int main(){
	cin >> n;
	func();
	return 0;
}
