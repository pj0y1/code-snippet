#include <iostream>
#include <string>

using namespace std;

int main(){
	int n ;
	cin  >> n;
	string vote;
	string max_vote = "";
	int idx;
	for(int i = 1; i <= n; i++){
		cin >> vote;
		if (vote.size() == max_vote.size()){
			if(vote >= max_vote){
				max_vote = vote;
				idx = i;
			}
		} else if (vote.size() > max_vote.size()){
			max_vote = vote;
			idx = i;
		}
	}
	cout << idx << endl << max_vote << endl;
	return 0;
}
