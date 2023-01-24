#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_LEN 100000

using namespace std;

int m, n, seat[MAX_LEN+5];


int main(){
	int max = 0;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++){
		scanf("%d", &seat[i]);
	}
	sort(seat, seat+m);
	int l = 1, r = seat[m-1] - seat[0];
	while(l != r){
		int mid = (l + r+ 1)/2;
		int t = 1, last = 0;
		for(int j = 1; j < m; j++){
			if (seat[j] - seat[last] >= mid){
				t++;
				last = j;
			}
//			printf("j=%d, t=%d, last=%d\n", j, t, last);
		}
//		printf("t=%d, mid=%d, l=%d, r=%d\n", t, mid, l, r);
		if(t >= n){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	printf("%d\n", l);
	return 0;
}
