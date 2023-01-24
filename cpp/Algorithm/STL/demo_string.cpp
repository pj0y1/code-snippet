#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
/* str.find("what", from=0) 找不到的话返回string::npos size_t -1
 * str.insert(index, "what")
 * str.substr(index, length)
 * str.replace(index, length, "what")
 */

int main(){
	string s = "Happy Birthday";
	if ( s < "Go4math") {
	
	} else {
		cout << s.length() << " " << (s.length() == s.size()) << endl;
		s += ", Peijun!";
		int pos = s.find("Peijun", 0);
		cout << "Found Peijun at " << pos << endl;
		cout << s << endl;
		cout << s.size() << endl;
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;

}
