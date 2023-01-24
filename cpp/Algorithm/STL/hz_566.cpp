#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int n, m;

int main(){
	cin >> n >> m;
	string user, page;
	vector<string> username;
	map<string, vector<string> > record;
	for(int i = 0; i < m; i++){
		cin >> user >> page;
		if(record.count(user) == 0) username.push_back(user);
		record[user].push_back(page);
	}
	for(int i = 0; i < username.size(); i++){
		cout << username[i];
		for(int j = 0; j < record[username[i]].size(); j++){
			cout << " " << record[username[i]][j];
		}
		cout << endl;
	}
	return 0;
}
