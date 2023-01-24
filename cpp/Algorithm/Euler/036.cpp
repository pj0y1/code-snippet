#include <iostream>

using namespace std;
// ans: 872187
int isPalindrome(int n, int base){
	int old = n;
	int r = 0;
	while(n){
		r *= base;
		r += n%base;
		n /= base;
	}
	return r==old;
}

int main(){
	long long ans = 0;
	for(int i=1; i< 1000000;i++){
		if(isPalindrome(i, 10) && isPalindrome(i,2)){
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
