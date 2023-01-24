#include <iostream>
using namespace std;
// ans: 4613732
int main(){
	int a=1, b=2;
	long long ans = 0;
	while (a < 4000000){
		if (a % 2 == 0)
			ans += a;
		b = a + b;
		a = b-a;
	}
	cout << ans << endl;
	return 0;
}
