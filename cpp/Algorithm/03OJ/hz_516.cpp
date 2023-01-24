#include <cstdio>
// 利用前缀和
using namespace std;

int n;
char s[100005];
int c_cnt[100005]; // 当前位置及之前的C的次数
int w_cnt[100005]; // 当前位置及之后出现的W的次数

int main(){
	scanf("%d", &n);
	scanf("%s", s);

	long long ans = 0;
	int tmp = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'C') tmp++;
		c_cnt[i] = tmp;
	}
	tmp = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == 'W') tmp ++;
		w_cnt[i] = tmp;
	}
	for (int i = 0; i < n; i++){ // 这一步和计算C的前缀和都是正序的 可省略一次循环
		if(s[i] == 'O') ans += c_cnt[i] * w_cnt[i];
//		printf("c_cnt[%d]=%d, w_cnt[%d]=%d\n", i, c_cnt[i], i, w_cnt[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
