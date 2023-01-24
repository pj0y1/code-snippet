#include <iostream>
#include <vector>
using namespace std;
/* vector 连续内存空间组成 随机访问下标的时间复杂度是常数
 * vector<int> v(5, 1); # 空间为5 每个元素初始化为1
 *
 * 1. v.size()
 * 2. v.push_back(x); 尾部插入x
 * 3. v[4] 通过下标访问
 * 4. v.capacity()
 * 
 * 扩容操作
 *
 * */

int main(){
	vector<int> v;
	vector<vector<int>> v2d(5, vector<int>(4, 3));
	for(int i = 0; i < v2d.size(); i++){
		for(int j=0; j < v2d[i].size(); j++){
			cout << v2d[i][j] << " ";
		}
		cout << endl;
	}
	/*
	for(int i = 0; i < 6; i++){
		v.push_back(i);
	}
	cout << v.size() << endl;
	*/
	return 0;
}
