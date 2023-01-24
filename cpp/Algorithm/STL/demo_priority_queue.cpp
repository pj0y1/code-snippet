#include <iostream>
#include <queue>
#include <functional>  // 为了引入greater

using namespace std;
/* 优先级队列 堆 
 *
 * 小顶堆和大顶堆
 * q.size()
 * q.push()
 * q.pop()
 * q.top()
 * q.empty()
 *
 * 使用自定义类型
 * */

struct node {
	int x, y;
	// 法1 重载小于号
	bool operator< (const node &b) const {
		return this-> x < b.x;
	}
};

// 法2 仿函数
struct cmp {
	bool operator() (const node &a, const node &b) {
		return a.x < b.x;
	}
	// priority_queue<node, vector<node>, cmp> pq;
};

int main(){
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 10; i > 0; i--){
		pq.push(i);
	}
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}
