#include <cstdio>
#include <queue>

using namespace std;

int x, y, n;

int main(){
	scanf("%d %d %d", &x, &y, &n);
	queue<int> m;
	queue<int> f;
	for(int i= 1; i <= x; i++){
		m.push(i);
	}
	for(int i= 1; i <= y; i++){
		f.push(i);
	}
	for(int i = 0; i< n; i++){
		int t1 = m.front(), t2 = f.front();
		printf("%d %d\n", t1, t2);
		m.pop();
		f.pop();
		m.push(t1);
		f.push(t2);
		
	}
	return 0;
}
