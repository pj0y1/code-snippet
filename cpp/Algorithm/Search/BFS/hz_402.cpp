#include<iostream>
#include <queue>
using namespace std;

int n, a, b;

int s[205], mark[205];

struct node {
	int x, step;
};


int main(){
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	queue<node> q;
	q.push((node){a, 0});
	mark[a] = 1;

	while(!q.empty()){
		node t = q.front();
		//cout << t.x << endl;
		q.pop();
		if(t.x == b){
			cout << t.step << endl;
			return 0;
		}

		if(t.x + s[t.x] <=  n && mark[t.x+s[t.x]] == 0){
			mark[t.x+s[t.x]] = 1;
			q.push((node){t.x+s[t.x], t.step+1});
		}
		if(t.x - s[t.x] >  0 && mark[t.x-s[t.x]] == 0){
			mark[t.x-s[t.x]] = 1;
			q.push((node){t.x-s[t.x], t.step+1});
		}
		
	}
	cout << -1 << endl;

	return 0;
}
