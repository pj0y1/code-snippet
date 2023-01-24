#include <cstdio>
#include <queue>

using namespace std;

int n, x, t;

bool hasSeven(int num){
	while(num){
		if(num % 10 == 7)
			return true;
		num /= 10;
	}
	return false;
}

int main(){
	queue<int> q;
	scanf("%d %d %d", &n, &x, &t);
	for(int i = 0; i < n; i++){
		int tmp = (x+i) % n;
		tmp = tmp == 0? n: tmp;
		q.push(tmp);
	}
	int idx = t;
	while(q.size() > 1){
		if (idx % 7 == 0 || hasSeven(idx)){
			q.pop();
		} else{
			q.push(q.front());
			q.pop();
		}
		idx++;
	}
	printf("%d\n", q.front());
	return 0;
}
