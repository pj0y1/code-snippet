#include <iostream>

using namespace std;

int n, num[15];

void comb(int start, int idx){
	for(int i = start; i <= n; i++){
		num[idx] = i;
		for(int j = 0; j <= idx; j++){
			if(j > 0) cout << " ";
			cout << num[j];
		}
		cout << endl;
		comb(i+1, idx+1);
	}
}


int main(){
	cin >> n;
	comb(1,0);
	return 0;
}
