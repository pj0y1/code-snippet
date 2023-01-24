#include <cstdio>
#include <map>

using namespace std;
/* 暴力算法
 * 二分查找
 * 哈希查找 标记数组 或容器
 * 双指针法 利用数组有序
 * */

int main(){
	int n, target, tmp;
	scanf("%d %d", &n, &target);
	map<int, int> cache;
	for(int i=0; i <n; i++){
		scanf("%d", &tmp);
		cache[tmp] = i;
	}
	for(auto it = cache.begin(); it != cache.end(); it++){
		int hit = cache.count(target-it->first);
		if(hit){
			printf("%d %d\n", it->second, cache[target-it->first]);
			return 0;
		}
	}
	return 0;
}
