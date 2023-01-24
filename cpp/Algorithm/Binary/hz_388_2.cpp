// 使用set
#include <cstdio>
#include <set>

using namespace std;

int numm[100005];

int main(){
	int m, n, tmp, space=0;
	long long sum = 0;
	set<int> numn;
	scanf("%d%d", &m, &n);
	for(int i=0; i<m; i++){
		scanf("%d", numm+i);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		numn.insert(tmp);
	}
	for(int i=0; i<m; i++){
		if(numn.find(numm[i]) != numn.end()){
			space && printf(" ");
			printf("%d", numm[i]);
			space = 1;
			sum += numm[i];
		}
	}
	printf("\n");
	printf("%lld\n", sum);
	return 0;
}
