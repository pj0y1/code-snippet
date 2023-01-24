#include <cstdio>
#include <algorithm>

using namespace std;

struct indexed {
	int idx, val;
};


int numn[100005];
indexed numm[100005];

int search(int target, int * arr, int start, int end){
	int left = start, right = end-1;
	int mid;
	while(left <= right){
		mid = (left+right)/2;
		if(arr[mid]==target){
			return 1;
		}else if (arr[mid] > target){
			right = mid-1;
		}else{
			left = mid+1;
		}
	}
	return 0;
}

bool cmp(const indexed &a, const indexed &b){
	if(a.val == b.val){
		return a.idx < b.idx;
	}else{
		return a.val < b.val;
	}
}

bool cmp2(const indexed &a, const indexed &b){
	return a.idx < b.idx;
}

int total = 0;
indexed tmp[100005];

int main(){
	int m, n, space=0;
	long long sum=0;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++){
		scanf("%d", &numm[i].val);
		numm[i].idx = i;
	}

	for(int i = 0; i < n; i++){
		scanf("%d", numn+i);
	}
	sort(numm, numm+m, cmp);
	sort(numn, numn+n);
	int l = 0, idx=1;
	for(int i=0; i < m; i++){
		int r= n-1, mid;
		while(l <= r){
			mid = (l+r)/2;
			if (numm[i].val == numn[mid]){
				/*space && printf(" ");
				printf("%d", numm[i]);
				sum += numm[i];
				space = 1;*/
				l = mid;
				total ++;
				tmp[total-1]=numm[i];
				sum += numm[i].val;
				break;
			} else if(numm[i].val > numn[mid]){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}
	}
	sort(tmp, tmp+total, cmp2);
	for(int i = 0; i < total; i++){
		i && printf(" ");
		printf("%d", tmp[i].val);
	}
	printf("\n");
	printf("%lld\n", sum);
	return 0;
}
