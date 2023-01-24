//均分纸牌
#include <iostream>

using namespace std;

int point[105];

int main(){
	int n, avg = 0;
	cin >> n;
	for(int i = 0; i< n; i++){
		cin >> point[i];
		avg += point[i];
	}
	avg /= n;
	int ans = 0;
	for(int i = 0; i < n-1; i++){
		if (point[i] < avg){
			point[i+1] -= avg-point[i];
			ans++;
		} else if (point[i] > avg){
			point[i+1] += point[i] - avg;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
