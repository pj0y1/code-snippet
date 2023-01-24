#include <cstdio>
#include <algorithm>

using namespace std;

int r, num[15][2];

int main(){
	scanf("%d", &r);
	int idx = 0, n=1, cnt = 0;
	int team[16];
	while(~n && cnt < 16 * 10){
		scanf("%d", &n);
		team[idx] = n;
		if(idx == 15){
			sort(team, team+8);
			sort(team+8, team+16);
			if(team[0] < team[8]){
				for(int i = 0; i < 8; i++){
					if(team[i] <= r && team[i] < team[8]) num[cnt/16][0]++;
				}

			}else{
				for(int i = 8; i < 16; i++){
					if(team[i] <= r && team[i] < team[0]) num[cnt/16][1]++;
				}
			
			}
		}
		idx = (idx+1) % 16;
		cnt ++;
	}
	cnt--;
	int total1=0, total2=0;
	for(int i = 0; i < cnt; i+=16){
		total1 += num[i/16][0];
		total2 += num[i/16][1];

		printf("%d:%d\n", num[i/16][0], num[i/16][1]);
	}
	printf("%d:%d\n", total1, total2);

	return 0;
}
