#include <iostream>

using namespace std;
// ans: 443839
int main(){
	int cache[10] = {0};
	for (int i = 1; i < 10; i++){
		cache[i] = i*i*i*i*i;
	}
	int ans = 0;
	int sum, tmp;
	for(int i = 10; i < 1000000; i++){
		tmp = i;
		sum = 0;
		while(tmp){
			sum += cache[tmp%10];
			tmp /= 10;
		}
		if (sum == i){
			ans += i;
		}
		
	}
	cout << ans << endl;
	return 0;
}
