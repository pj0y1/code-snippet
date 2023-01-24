#include <cstdio>

using namespace std;
/* 二分答案 11110000类型
 *
 * */
int t, n, m, pos[50005];

int main(){
	scanf("%d%d%d", &t, &n, &m);
	int prev = 0, min_step = 100000;
	for(int i = 0; i < n; i++){
		scanf("%d", &pos[i]);
		min_step = min_step < pos[i]-prev? min_step: pos[i] - prev;
		prev = pos[i];
	}
	pos[n] = t;
	int l = min_step, r = t;
	while(l < r){
		int mid = (l+r+1)/2;
		int cnt = 0, last = 0, hit = 0;
		for(int j = 0; j <= n; j++){
			if(pos[j] - last >= mid){
				last = pos[j];
			}else{
				cnt++;
			}
		}
//		printf("cnt=%d, mid=%d, l=%d, r=%d\n", cnt, mid, l, r);		
		if(cnt > m){
			r = mid-1;
		}else{
			l = mid;
		}
	}
	printf("%d\n", l);
	return 0;
}


