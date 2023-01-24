#include <cstdio>
#include <queue>

using namespace std;

struct node {
	int t, c;
};

int n, mark[100005], ans;

int main(){
	scanf("%d", &n);
	queue<node> q;
	for(int i=0; i < n; i++){
		int t, cnt;
		scanf("%d%d", &t, &cnt);
		while(!q.empty() && t-q.front().t >= 86400){
			mark[q.front().c]--;
			if(mark[q.front().c] == 0){
				ans--;
			}
			q.pop();
		}
		for(int j = 0; j < cnt; j++){
			int tmp;
			scanf("%d", &tmp);
			q.push((node){t, tmp});
			mark[tmp]++;
			if(mark[tmp] == 1){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
