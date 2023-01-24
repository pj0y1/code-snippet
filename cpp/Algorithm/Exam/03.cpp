#include <iostream>

using namespace std;
// 二分答案类型
int n, m;

int num[100005], price[100005];

int main(){
	cin >> n >> m;
	int l = 0, r = 0;
	for(int i = 0; i < n; i++){
		cin >> num[i];
		r = max(r, num[i]);
	}
	cout << "r " << r << endl;
	for(int i = 0; i < n; i++){
		cin >> price[i];
	}

	while(l < r){
		int mid = (l+r)/2;

		long long total = 0;
		for(int i = 0; i < n; i++){
			int cnt = min(num[i], mid);
			total += cnt * price[i];
		}
		cout << "total " << total << " mid " << mid << endl;
		if(total < m){
			l=mid+1;
		}else{
			r = mid;
		}
	}
	cout << l << endl;
	return 0;
}
