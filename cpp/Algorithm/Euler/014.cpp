#include <iostream>
#include <map>
#define SIZE 1000000

using namespace std;

// ans: 837799

int hailstone(long long  n, map<int, int>& cache){
	int ret;
	if(n == 1)
		return 1;
	auto hit = cache.find(n);
	if (hit != cache.end()){
		return hit->second;
	}
	if(n%2)
		ret = hailstone(n*3+1, cache)+1;
	else
		ret = hailstone(n/2, cache)+1;
	
	cache[n] = ret;
	return ret;
}


int main(){
	int ans=-1, max_len=0;
	map<int, int> cache = {};
	for(long long i=1; i<= SIZE; i++){
		int len = hailstone(i, cache);
		if(len > max_len){
			max_len = len;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
