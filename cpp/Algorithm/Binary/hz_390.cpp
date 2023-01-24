#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int len[100005], n, m, l=0, r;

int func(int x){
	int t = 0;
	for(int i = 0; i < n; i++){
		t += len[i]/x;
	}
	return t;
}

int bs(){
	while(l != r){
		int mid = ((long long)l + r + 1)/2;
		int t = func(mid);
		if (t >= m){
			l = mid;
		}else {
			r = mid-1;
		}
	}
	return r;
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", len+i);
		r = max(r, len[i]);
	}
	printf("%d\n", bs());
	return 0;
}
