#include <iostream>
#include <queue>

using namespace std;

int n, tmp;

int main(){
	cin >> n;
	priority_queue<int> q;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		q.push(-tmp);
	}
	int ans = 0;
	while(!q.empty()){
		tmp = q.top();
		q.pop();
		if(q.empty()) {
			cout << -ans << endl;
			return 0;
		}
		tmp += q.top();
		ans += tmp;
		q.pop();
		q.push(tmp);
	}
	return 0;
}
