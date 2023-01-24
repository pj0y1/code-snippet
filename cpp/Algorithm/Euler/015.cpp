#include <iostream>

using namespace std;
// ans: 137846528820
int main(){
	int n = 20, m = 40;
	long long ans = 1;
	for(int i = 1; i<=n; i++){
		ans *= m-i+1;
		ans /= i;
	}
	cout << ans << endl;
	return 0;
}
