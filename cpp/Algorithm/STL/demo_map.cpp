#include <iostream>
#include <map>

using namespace std;

int main(){
	map<int, int> counter;
	counter.insert(make_pair(10,12));
	counter[10] += 100;
	for(auto it=counter.begin(); it != counter.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	cout << counter.size() << endl;
	// m.count() -> 1, 0
	// m.erase()
	// m[10]
	return 0;
}
