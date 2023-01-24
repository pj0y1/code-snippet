#include <iostream>

using namespace std;

int num[2][1005] = {{1,1}, {1,1}};
// ans: 4782
int hit(int flag){
	int idx;
	if(flag){
		idx = 1; // num[0] + num[1] => num[1]
	}else{
		idx = 0; // num[1] + num[0] => num[0]
	}

	int t = max(num[0][0], num[1][0]);
	int carry = 0;
	for(int i = 1; i <= t || carry > 0; i++){
		int tmp = num[0][i] + num[1][i] + carry;
		carry = tmp / 10;
		num[idx][i] = tmp % 10;
		num[idx][0] = max(num[idx][0], i);
	}
	if(num[idx][0] >= 1000)
		return 1;
	else
		return 0;
}

int main(){
	int a = 0, b = 1;
	int flag = 1;
	for(int i =3; 1; i++){
		if(hit(flag)){
			cout << i << endl;
			break;
		}
		flag = !flag;
	}
	return 0;
}
