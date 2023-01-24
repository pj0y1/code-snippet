#include <iostream>
#include <queue>

using namespace std;

char s[500005];

int one_beg, zero_beg, one_cnt, zero_cnt;

int findMax(queue<int>& q, int * start){
	if(q.size() == 1){
		*start = q.front();
		q.pop();
		return 1;
	}
	int cnt = 1, max_cnt = 1;
	int prev = q.front();
	int max_start = prev;
	q.pop();
	int cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if (cur == prev + 1) {
			cnt ++;
			prev = cur;
		}
		else {
			if(cnt >= max_cnt){
				max_cnt = cnt;
				max_start = prev - cnt + 1;
			}
			cnt = 1;
			prev = cur;
		}

	}
	if(cnt >= max_cnt){
		max_cnt = cnt;
		max_start = cur - cnt + 1;
	}
	*start = max_start;
	return max_cnt;

}


int main(){
	cin >> &s[1];
	queue<int> one;
	queue<int> zero;
	int i = 1;
	while(s[i] != 0){
		if(s[i] == '1'){
			one.push(i);
		}else if (s[i] == '0'){
			zero.push(i);
		}
		i++;
	}
	one_cnt = findMax(one, &one_beg);
	zero_cnt = findMax(zero, &zero_beg);
	cout << zero_cnt << " " << zero_beg << " " << zero_beg + zero_cnt -1 << endl;
	cout << one_cnt << " " << one_beg << " " << one_beg + one_cnt -1 << endl;
	return 0;
}
