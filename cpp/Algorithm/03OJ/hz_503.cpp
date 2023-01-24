//独木舟
// 排序+双指针
#include <iostream>
#include <algorithm>
using namespace std;

int weight[30005];

int main(){
	int cap, n;
	cin >> cap >> n;
	for(int i = 0; i< n; i++){
		cin >> weight[i];
	}

	sort(weight, weight+n);
	int l=0, r=n-1, ans=0;
	while(l < r){
		if(weight[l] + weight[r] <= cap){
			l++;
			r--;
		}else{
			r--;
		}
		ans++;
//		cout << l << " " << r << endl;
	}
	if(l == r) ans++;
	cout << ans << endl;
	return 0;
}
