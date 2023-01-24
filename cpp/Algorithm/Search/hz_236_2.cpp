#include<iostream>

using namespace std;

int n, m, num[15];

void func(int start, int left){
	if(left == 0){
		for(int i = 0; i < m; i++){
			if(i)
				cout << " "<< num[i];
			else
				cout << num[i];
		}
		cout << endl;
		return;
	}
	for(int i = start; i <= n-left+1; i++){
		num[m-left] = i;
		func(i+1, left-1);
	}
}

int main(){
	cin >> n >> m;
	func(1, m);

	return 0;
}
