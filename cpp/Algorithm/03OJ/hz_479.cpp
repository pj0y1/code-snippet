#include <cstdio>
#include <cmath>

using namespace std;
// 模拟过程

int ans11[10005][2], ans21[5005][2], idx11, idx21;
char str[30];


int main(){
	while(~scanf("%s", str)){
		for(int i = 0; str[i]; i++){
			if(str[i] == 'E'){
				for(int i = 0; i <= idx11; i++)
					printf("%d:%d\n", ans11[i][0], ans11[i][1]);
				printf("\n");
				for(int i = 0; i <= idx21; i++)
					printf("%d:%d\n", ans21[i][0], ans21[i][1]);
				return 0; // todo
			}
			if (str[i] == 'W'){
				ans11[idx11][0]++;
				ans21[idx21][0]++;
			}else{
				ans11[idx11][1]++;
				ans21[idx21][1]++;
			}
			if(fmax(ans11[idx11][0], ans11[idx11][1]) >= 11 && abs(ans11[idx11][1] - ans11[idx11][0]) >= 2){
					idx11++;
			}
			if(fmax(ans21[idx21][0], ans21[idx21][1]) >= 21 && abs(ans21[idx21][1] - ans21[idx21][0]) >= 2){
					idx21++;
			}
		}
	}
	return 0;
}
