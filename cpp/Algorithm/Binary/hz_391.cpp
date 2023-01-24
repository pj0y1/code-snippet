#include <cstdio>
#include <algorithm>

/* 二分答案 00001111的情况
 *
 * */
using namespace std;

int n, m, arr[100005];
long long acc[100005];

int main(){
	int max_len = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
		max_len = arr[i] > max_len? arr[i] : max_len;
	}
	long long sum = 0;
	for(int i = 0; i <= n; i++){
		sum += arr[i];
		acc[i] = sum;
	}
	long long l = max_len, r = acc[n];
	while(l < r){
		long long mid = (l+r)/2;
		int cnt = 0, flag = 0;
		long long prev = 0;
		for( int i = 0; i <= n; i++){
			if (acc[i] - prev == mid){
				cnt++;
				prev = acc[i];
				flag = 1;
			}else if (acc[i] - prev > mid){
				prev = acc[i-1];
				cnt++;
			}
		}
		if(prev != acc[n]) {
			cnt ++;
		}
//		printf("cnt=%d, mid=%lld, l=%lld, r=%lld\n", cnt, mid, l, r);
		if(cnt > m){
			l = mid+1;
		}else if (flag){
			r = mid;
		}else{
			r = mid-1;
		}
	}
	printf("%lld\n", l);
	return 0;

}
