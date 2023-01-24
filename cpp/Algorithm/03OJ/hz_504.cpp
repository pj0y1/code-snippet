#include <iostream>
#include <string>

using namespace std;

int main(){
	string num;
	int n;
	cin >> num >> n;
	for(int i=0; i < n; i++){
		int idx = num.size()-1;
		for(int j = 0; j < num.size()-1; j++){
			if(num[j] > num[j+1]){
				idx = j;
				break;
			}
		}
		num.replace(idx, 1, "");
	}
	int f = 0;
	for(int i = 0; i < num.size(); i++){
		if(f){
			cout << num[i];
		} else if( num[i] != '0') {
			cout << num[i];
			f = 1;
		}
	}
	cout << endl;
	return 0;
}
