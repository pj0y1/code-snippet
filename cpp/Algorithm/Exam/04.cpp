#include <iostream>
#include <vector>

using namespace std;

struct node {
	char c; 
	int n;
};

char num[50];

void print(int pos){
	for(int i = 0; i <= pos; i++){
		cout << num[i];
	}
	cout << endl;
}

void func(vector<node> &v, int cur, int pos){
	if(cur == v.size()) {
		print(pos);
	}
	for(int i = 1; i <= v[cur].n; i++){
		num[pos+i]=v[cur].c;
		func(v, cur+1, pos+i);
	}

}


int main(){
	string s;
	vector<node> v;
	cin >> s;
	int pos = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != s[pos]){
			v.push_back((node){s[pos], i-pos});
			pos = i;
		}
	}
	if(pos < s.size()){
		v.push_back((node){s[pos], (int)s.size()-pos});
	}
	func(v, 0, 0);
	return 0;
}
