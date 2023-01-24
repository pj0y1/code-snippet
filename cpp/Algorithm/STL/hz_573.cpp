#include <iostream>
#include <string>
#include <queue>
#include<map>

using namespace std;

struct node {
	int qnum, time;
	bool operator< (const node &b) const {
		if(this->time != b.time)
			return this->time < b.time;
		return this->qnum > b.qnum;
	}
};

int k;

int main(){
	string word;
	int qnum, time;
	priority_queue<node> q;
	map<int, int> m;
	do{
		cin >> word;
		if(word == "#") break;
		cin >> qnum >> time;
		m[qnum] = time;
		q.push((node){qnum, -time});
	}while(word != "#");
	cin >> k;
//	cout << "q.size()=" << q.size() << endl;
	for(int i = 0; i < k; i++){
		if(!q.empty()){
			node n = q.top();
			cout << n.qnum << endl;
			q.pop();
			n.time -= m[n.qnum];
			q.push(n);
		}
	}
	return 0;

}
