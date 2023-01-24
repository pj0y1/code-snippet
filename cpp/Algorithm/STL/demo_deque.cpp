#include <iostream>
#include <deque>

using namespace std;

/* deque 容器
 * deque<int> dq;
 * dq.size();
 * dq.push_front();
 * dq.push_back();
 * dq.pop_front();
 * dq.pop_back();
 * dq.empty();
 * dq[9]
 * */

int main(){
	deque<int> dq;
	dq.push_back(5);
	dq.push_back(8);
	dq.push_front(9);
	dq.push_front(2);
	for(int i = 0; i < dq.size(); i++){
		cout << dq[i] << endl;
	}
	return 0;
}
