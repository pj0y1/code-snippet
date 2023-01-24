#include <cstdio>

using namespace std;
// 枚举
// 可以省略gcd的步骤 因为是从小枚举到大
int gcd(int i, int j){
	if(i < j){
		i = i+j;
		j = i-j;
		i = i-j;
	}
	int r;
	do{
		r = i % j;
		i = j;
		j = r;
	} while(r);
	return i;
}


int main(){
	int a, b, l;
	scanf("%d%d%d", &a, &b, &l);
	int x, y;
	float k = float(a)/b, m = float(l);
	for (int i = 1; i <= l; i++){
		for(int j = 1; j <= l; j++){
			float tmp = float(i)/j;
			if(tmp >= k && tmp - k < m && gcd(i, j) == 1){
				x = i;
				y = j;
				m = tmp - k;
			}
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}
