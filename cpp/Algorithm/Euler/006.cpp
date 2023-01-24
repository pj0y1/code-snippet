#include <iostream>

using namespace std;
// ans : 25164150
int main(){
	int a = 0, b = 0;
	for(int i = 1; i <= 100; i++){
		a += i*i;
		b += i;
	}
	cout << b*b - a << endl;
	return 0;
}
