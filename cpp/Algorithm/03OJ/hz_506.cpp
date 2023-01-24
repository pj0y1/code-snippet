#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct info {
	int idx, time;
};

bool cmp(const info&a, const info&b){
	return a.time < b.time;
}

info arr[35];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i< n; i++){
		scanf("%d", &arr[i].time);
		//cin >> arr[i].time;
		arr[i].idx = i+1;
	}

	sort(arr, arr+n, cmp);
	float total = 0;
	for(int i = 0; i<n-1; i++){
		total += (n-i-1)*arr[i].time;
	}
	for(int i = 0; i<n; i++){
		//i && cout << " ";
		//cout << arr[i].idx;
		i && printf(" ");
		printf("%d", arr[i].idx);
	}
//	cout << endl << total/n << endl;
	printf("\n%.2f\n", total/n);
	return 0;
}
