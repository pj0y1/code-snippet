#include <iostream>

using namespace std;
// ans: 906609
int isPalindrome(int n){
	int r = 0, old=n;
	while (n){
		r *= 10;
		r += n%10;
		n /= 10;
	}
	return old==r;
}

int main(){
	int ans = 0;
	int tmp;
	for(int i=100; i < 1000; i ++){
		for(int j =i; j < 1000; j++){
			tmp = i*j;
			if(isPalindrome(tmp)){
				ans = ans > tmp? ans: tmp;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
