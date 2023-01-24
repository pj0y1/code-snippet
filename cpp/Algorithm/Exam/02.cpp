#include <iostream>
#include <algorithm>
#include <string>
// 单词反转
using namespace std;

int main(){
	string sentence;
	getline(cin, sentence);
	int prev = 0;
	for(int i = 0; i < sentence.size(); i++){
		if(sentence[i] == ' '){
			for(int j= prev, k= i-1; j < k; j++, k--){
				char tmp;
				tmp = sentence[j];
				sentence[j] = sentence[k];
				sentence[k] = tmp;
			}
			prev = i+1;
		} else if (sentence[i] == '.'){
			for(int j= prev, k= i-1; j < k; j++, k--){
				char tmp;
				tmp = sentence[j];
				sentence[j] = sentence[k];
				sentence[k] = tmp;
			}
		}
	}
	cout << sentence << endl;
	return 0;
}

