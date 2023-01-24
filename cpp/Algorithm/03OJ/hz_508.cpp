#include <iostream>
#include <algorithm>

using namespace std;

int num[1005];

int main(){
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> num[i];
	}
	sort(num, num+n);
	for(int i = n-1; i>= 0; i-=2){
		if (i == 0){
			ans += num[0];
		} else if (i == 1){
			ans += num[1];
		}else if (i == 2){
			ans += num[1] + num[2];
		}else {
			ans += min(num[i] + num[0] + num[i-1] +num[0], num[1]+num[0]+num[i]+num[1]);
		}
	}

	cout << ans << endl;
	return 0;
}
