#include<cstdio>
#include<map>

using namespace std;

int main(){
	map<int, int> wm;
	int m, n, tmp;
	scanf("%d%d", &m, &n);
	for(int i=1; i<=m; i++){
		scanf("%d", &tmp);
		wm[tmp] = i;
	}
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		int hit = wm.count(tmp);
		if(hit){
			printf("%d\n", wm[tmp]);
		}else{
			printf("0\n");
		}
	}
	return 0;
}
