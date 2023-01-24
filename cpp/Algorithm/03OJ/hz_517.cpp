#include <cstdio>

using namespace std;
// 枚举
// 为了避免重复 从最长边开始枚举 i >= j >= n-i-j > 0
int n;

int main(){
	scanf("%d", &n);
	int ans = 0;
	for(int i=n/2; i > 0; i--){
		for(int j = i; j >= n-i-j ; j--){
			if(n-i-i > 0 && i+j > n-i-j) {
				ans ++;
//				printf("i=%d, j=%d, n-i-j=%d\n", i, j, n-i-j);
			}
		}
		
	}
	printf("%d\n", ans);
	return 0;
}
