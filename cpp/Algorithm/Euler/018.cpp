#include <iostream>

using namespace std;

int num[20][20], dp[20][20];
// ans : 1074

int main(){
	for(int i = 1; i <= 15; i++)
		for(int j = 1; j<= i; j++){
			cin >> num[i][j];
		}

	int ans =0;
	for(int i = 1; i <= 15; i++){
		for(int j=1; j<= i; j++){
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num[i][j];
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
