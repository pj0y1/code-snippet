#include <cstdio>

using namespace std;

int x;

int main(){
	scanf("%d", &x);
	int ans = 0, turn=1;
	int i = 1;
	while(i <= x){
		for(int j = turn; i <= x && j > 0; j--){
			ans += turn;
			i++;
		}
		turn++;
	}
	printf("%d\n", ans);
	return 0;
}
