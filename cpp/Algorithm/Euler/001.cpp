#include <iostream>
using namespace std;

// ans : 233168

int main(){
	int ans = 0;
	ans += (3+999)*(996/3+1)/2;
	ans += (5+995)*(990/5+1)/2;
	ans -= (15+990)*(975/15+1)/2;
	cout << ans << endl;
	return 0;
}
