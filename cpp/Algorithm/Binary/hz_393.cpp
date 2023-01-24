#include <cstdio>
#include <algorithm>

using namespace std;
/* 类似390原木切割 但是处理数据不再是整型
 *
 * 循环条件变了 while(R-L > eps) eps = 1e-6
 * LR变化也不再+1或-1 而是直接L=mid 或R=mid
 *
 * 二分答案
 *
 * 输出带两位小数 
 * 法1 1.2345 * 100 -> int(123.45) -> 123/100 -> 1.23
 * 法2 1.2345 - 0.005 -> printf("%.2lf", num); 会round到1.23
 */
int n, k;
double len[100005];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%lf", &len[i]);
	}
	sort(len, len+n);
	double l = 0.0, r = len[n-1];
	while(r-l > 1e-6){
		double mid = (l+r)/2;
		int cnt = 0;
		for(int j = 0; j < n; j++){
			cnt += int(len[j]/mid);
		}
		if(cnt >= k){
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%.2lf\n", l-0.005);

	return 0;
}
