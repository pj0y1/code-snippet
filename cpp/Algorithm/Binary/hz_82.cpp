#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, height[1000005];


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &height[i]);
	}
	sort(height, height+n);
	int l = 0, r = height[n-1];
	while( l < r){
		int mid = (l + r + 1)/2;
		long long total = 0;
		for(int j = 0; j < n; j++){
			total += height[j] > mid ? height[j] - mid: 0;
		}
		if(total >= m){
			l = mid;
		} else {
			r = mid-1;
		}
	}
	printf("%d\n", l);
	return 0;
}
