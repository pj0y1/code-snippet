#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main(){
	cin >> n >> m;
	vector<int> v;
	v.push_back(n); // 其实是模拟了链表的尾插
	for(int i = 1; i< n; i++){
		v.push_back(i);
	}
	int elim_cnt = 0, pos = 0;
	while(elim_cnt < n){
		for(int i = 0; i < m ; ){
			pos = (pos+1) % v.size();
			if (v[pos] != -1){
				i++;
			}
		}
		//cout << "pos=" << pos << endl;
		v[pos] = -1;
		elim_cnt += 1;
	}
	if( pos == 0) pos = n; // 如果此时位置为0 其实对应的编号为n
	cout << pos << endl;
	return 0;
}
