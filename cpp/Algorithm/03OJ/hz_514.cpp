#include <cstdio>
#define MAX 881
using namespace std;
// 枚举 上界1111 其实我这里设置为881还是偏小了
int n;

int used[MAX+5];

int use(int num){
	if(num == 0)
		return 6;
	int cnt = 0;
	while(num){
		switch(num%10){
			case 0: cnt += 6; break;
			case 1: cnt += 2; break;
			case 2: cnt += 5; break;
			case 3: cnt += 5; break;
			case 4: cnt += 4; break;
			case 5: cnt += 5; break;
			case 6: cnt += 6; break;
			case 7: cnt += 3; break;
			case 8: cnt += 7; break;
			case 9: cnt += 6; break;
		}
		num /= 10;
	}
	return cnt;
}

int init(int num){
	int max_int;
	for(int i = 0; i <= MAX ; i ++){
		int cnt = use(i);
//		printf("i=%d, cnt=%d\n", i, cnt);
		used[i] = cnt;
		if(cnt <= num) max_int = i;
	}
	return max_int;
}

int main(){
	scanf("%d", &n);
	int ans = 0, repeat = 0;
	if(n > 4) {
		int repeat = 0;
		int max_int = init(n-8);
//		printf("max_int=%d\n", max_int);
		for(int i = 0; i <= max_int; i++){
			for(int j = 0; j <= max_int; j++){
				if (i+j <= max_int && used[i] + used[j] + used[i+j] == n-4){
					if (i == j) repeat++;
					ans ++;
				}
			}
		}

	}
	printf("%d\n", ans - repeat);
	return 0;
}
