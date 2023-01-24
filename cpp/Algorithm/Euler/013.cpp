#include <iostream>
#include <cstring>

using namespace std;

char str[100];
int num[100];
int sum[100];
// ans: 5537376230
int main(){
	for(int i = 0; i< 100; i++){
		cin >> str;
		int len = strlen(str);
		num[0] = len;
		for(int j=1; j<=len; j++){
			num[j] = str[len-j] - '0';
		}
		for(int j=len+1; j<100;j++){
			num[j] = 0;
		}
		int t = max(sum[0], num[0]);
		int carry = 0;
		for(int i = 1; i <= t || carry > 0; i++){
			int tmp = sum[i] + num[i] + carry;
			carry = tmp / 10;
			sum[i] = tmp % 10;
			sum[0] = max(sum[0], i);
		}

	}
	for (int i = sum[0]; i > sum[0]-10; i--){
		cout << sum[i];
	}
	cout << endl;
	return 0;
}
