#include <iostream>
#include <unordered_set>
#include <cstdio>
#include <queue>

using namespace std;

int n, k, effect[25];

struct node {
	int stat, step;
};


int main(){
	cin >> n; 
	int stat = 0;
	queue<node> que;
	unordered_set<int> vis;
	for(int i = 0; i < n; i++){
		int t = 0;
		cin >> t;
		stat |= t*(1 << i);

	}
//	cout << "stat " << stat << endl;
	for(int i = 0; i < n; i++){
		cin >> k;
		int s = (1<<n)-1;
		for(int j = 1; j <= k;  j++){
			int t;
			cin >> t;
			if(t == i+1) continue;
			s &= ~(1<< (t-1));
		}
		effect[i] = s;
//		printf("effect[%d] = %x\n", i, s);
	}

	que.push((node){stat, 0});
	vis.insert(stat);
	while(!que.empty()){
		node tmp = que.front();
//		cout << tmp.stat << " " << tmp.step << endl;
		que.pop();
//		int t = tmp.stat ^((1<<n)-1);
//		cout << "stat mask " << t << endl;
		for(int i = 0; i < n; i++){
			if((tmp.stat & (1 << i)) == 0){
//				cout << "I " << i << endl;
				int new_stat = tmp.stat & effect[i];
				new_stat |= (1<<i);
//				cout << "new stat " << new_stat << endl;
//				printf("new stat = %x\n", new_stat);
				if(new_stat == (1 << 2)){
					cout << tmp.step+1 << endl;
					return 0;
				}
				if (vis.count(new_stat) == 0){
					vis.insert(new_stat);
					que.push((node){new_stat, tmp.step+1});
				}
			}
		}
	}


	return 0;
}
