#include <cstdio>
#include <set>

using namespace std;

int n, tmp;

int main(){
	set<int> s;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d",&tmp);
		s.insert(tmp);
	}
	printf("%d\n", (int)s.size());
	for(auto it=s.begin(); it !=s.end(); it++){
		printf("%d ", *it);
	}
	printf("\n");
	return 0;
}
