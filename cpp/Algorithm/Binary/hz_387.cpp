#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct wm {
	int idx, num;
};

wm data[100005];

bool cmp( const wm &a, const wm &b){
	if(a.num == b.num){
		return a.idx < b.idx;
	}
	return a.num < b.num;
}

int main(){
	int m, n, target;
	//cin >> m >> n;
	scanf("%d %d", &m, &n);
	for(int i = 1; i<= m; i++){
		//cin >> data[i-1].num;
		scanf("%d", &data[i-1].num);
		data[i-1].idx = i;
	}
	sort(data, data+m, cmp);
	for(int i = 1; i <= n; i++){
		//cin >> target;
		scanf("%d", &target);
		int l = 0, r = m-1;
		if (data[m-1].num < target){
			//cout << 0 << endl;
			printf("%d\n", 0);
			continue;
		}
		while (l != r){
			int mid = (l+r)/2;
			if (data[mid].num < target){
				l = mid+1;
			}else {
				r = mid; 
			}
		}
		//cout << data[l].idx << endl;
		printf("%d\n", data[l].idx);
	}
	return 0;
}
