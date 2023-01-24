#include <iostream>
#include <set>
// 可以排序和去重
using namespace std;
/* Set
 * s.insert()
 * s.erase()
 * s.size()
 * s.count() -> 0, 1
 * 内部元素有序 从小到大 内部使用红黑树实现 平衡二叉树
 * */

struct node {
	int x, y;
	bool operator< (const node &b) const {
		return this->x < b.x;
	}
};

int main(){
	set<node> sn;
	sn.insert(node{1,10});
	sn.insert(node{4,6});
	sn.insert(node{7,2});
	for(auto it = sn.begin(); it != sn.end(); it++){
		cout << it->x << " " << it->y << endl;
	}
	for(auto it = sn.rbegin(); it != sn.rend(); it++){
		cout << it->x << " " << it->y << endl;
	}

	set<int> s;
	s.insert(5);
	cout << s.count(5) << endl;
	s.erase(5);
	cout << s.count(5) << endl;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	for(auto it = s.begin(); it != s.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
