#include<iostream>
#include<string>
#include<map>

using namespace std;

struct node {
	int p, c;
};

int n, k;

int main(){
	map<string, node> repo;
	cin >> n >> k;
	string name;
	int tp, tc, amt;
	for(int i = 0; i < n; i++){
		cin >> name >> tp >> tc;
		repo[name] = node{tp, tc};
	}
	long long profit = 0;
	for(int i = 1; i <= k; i++){
		cin >> name >> amt;
		if(repo[name].c >= amt) {
			repo[name].c -= amt;
			profit += repo[name].p * amt;
		}else{
			cout << "-" << i << endl;
			return 0;
		}
	}
	cout << profit << endl;
	return 0;
}
