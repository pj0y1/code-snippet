#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string data[100005];

bool cmp(const string &a, const string &b){
	return a+b > b+a;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> data[i];
	}
	sort(data, data+n, cmp);
	for(int i = 0; i< n; i++){
		cout << data[i];
	}
	cout << endl;
	return 0;
}
