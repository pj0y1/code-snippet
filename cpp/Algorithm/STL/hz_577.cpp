#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string word;
	map<string, int> dict;
	// getline(cin, s); todo
	while(cin >> word){
		for(int i = 0; i < word.size(); i++){
			if(word[i] <= 'Z') word[i] += 32; // lower
		}
		dict[word]++;
	}
	int freq = 0;
	string most_freq = "";
	for(auto it=dict.begin(); it != dict.end(); it++){
//		cout << it->first << " " << it->second << endl;
		if(it->second > freq || (it->second == freq && it->first < most_freq)){
			freq = it->second;
			most_freq = it->first;
		}
	}
	cout << most_freq << " " << freq << endl;
	return 0;
}
