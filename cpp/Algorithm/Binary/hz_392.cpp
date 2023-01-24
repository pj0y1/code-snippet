#include <cstdio>
#include <algorithm>
using namespace std;

// 丢瓶盖 仍然是二分答案类型 查找类型11110000


int a, b, pos[100005];

int main(){
	scanf("%d%d", &a, &b);
	int min_dis = 100000005;
	for(int i = 0; i < a; i++){
		scanf("%d", &pos[i]);
		if (i > 0){
			min_dis = min(pos[i] - pos[i-1], min_dis);
		}
	}
	sort(pos, pos+a);
	for(int i = 0; i < a; i++){
		if (i > 0){
			min_dis = min(pos[i] - pos[i-1], min_dis);
		}
	}
	int l= min_dis, r = pos[a-1] - pos[0];
	while(l < r){
		int mid = (l+r+1)/2;
		int cnt = 1, last = 0;
		for(int j = 1; j < a; j++){
			if(pos[j] - pos[last] >= mid){
				cnt++;
				last = j;
			}
		}
		if(cnt < b){
			r = mid-1;
		}else{
			l = mid;
		}
	}
	printf("%d\n", l);
	return 0;
}
