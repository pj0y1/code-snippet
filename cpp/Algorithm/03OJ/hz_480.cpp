#include <cstdio>

using namespace std;

struct node {
	char s[4];
	int num1, num2, flag;
};

node game[15];

int main(){
	for( int i = 1; ~scanf("%s", game[i].s); i++){
		if (game[i].s[0] == '/'){
			game[i].num1 = 10;
			game[i].num2 = 10;
			game[i].flag = 2;

		} else if(game[i].s[1] == '/'){
			game[i].num1 = game[i].s[0] - '0';
			game[i].num2 = 10;
			game[i].flag = 1;
			
		}else {
			game[i].num1 = game[i].s[0] - '0';
			game[i].num2 = game[i].s[1] - '0' + game[i].num1;
			game[i].flag = 0;
		
		}
	}
	int ans = 0;
	for(int i = 1; i <= 10; i++){
		ans += game[i].num2;
		if(game[i].flag == 1){
			ans += game[i+1].num1;
		}else if(game[i].flag == 2) {
			if(game[i+1].flag == 2){
				ans += 10 + game[i+2].num1;
			}else {
				ans += game[i+1].num2;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
