#include <iostream>
#define WIDTH 13
#define SIZE 1000
using namespace std;

char digits[SIZE+5];
// ans : 23514624000
int main(){
	cin >> digits;
	long long ans=1, tmp=1;
	int zero_count = 0;
	for(int i = 0; i < WIDTH; i++){
		if (digits[i] == '0')
			zero_count += 1;
		else
			tmp *= (digits[i] - '0');
	}
	ans = tmp;
	// cout << tmp << endl;
	for(int i=WIDTH; i< SIZE; i++){
		if(digits[i] == '0'){
			zero_count ++;
		} else {
			tmp *= (digits[i] - '0');
		}
		if (digits[i-WIDTH] == '0'){
			zero_count --;
		} else {
			tmp /= (digits[i-WIDTH] - '0');
		}
		if(zero_count == 0){
			ans = ans > tmp? ans: tmp;
		}
		// cout << tmp << endl;
	}
	cout << ans << endl;
	return 0;
}
