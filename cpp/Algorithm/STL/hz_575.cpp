#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;

int main(){
	cin >> n;
	string word;
	int page;
	map<string, int> dict;
	for(int i  = 0; i < n; i++){
		cin >> word >> page;
		dict[word] = page;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> word;
		cout << dict[word] << endl;
	}

	return 0;
}
