#include<iostream>
#include<unordered_set>
#include<vector>
#include<unordered_map>
using namespace std;

int n, m, max_cnt, min_len;

int main(){
	unordered_set<int> word;
	vector<int> essay;
	unordered_map<int, int>counter;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int t;
		cin >> t;
		word.insert(t);
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		int t;
		cin >> t;
		essay.push_back(t);
		if(word.count(t) == 1){
			counter[t]++;
		}
	}
	max_cnt = (int)counter.size();
	
	int start = 0, end = essay.size()-1;
	for(int i = 0; i < essay.size(); i++){
		if(word.count(essay[i]) == 0)
			start++;
		else{
			if(counter[essay[i]] > 1){
				start++;
				counter[essay[i]]--;
			}else{
				break;
			}
		}
	}
	for(int j = essay.size()-1; j > start; j--){
		if(word.count(essay[j]) == 0)
			end--;
		else{
			if(counter[essay[j]] > 1){
				end--;
				counter[essay[j]]--;
			}else{
				break;
			}
		}
	}
	cout << max_cnt << " " << end-start+1 << endl;
	return 0;
}
