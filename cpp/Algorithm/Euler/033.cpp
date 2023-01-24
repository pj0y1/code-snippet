#include <iostream>

using namespace std;
// ans: 100
int gcd(int a, int b){
	if (!b) return a;
	return gcd(b, a%b);
}

int check(int a, int b){
	int n1 = a/10, m1 = a%10;
	int n2 = b/10, m2 = b%10;
	if(!m1 || !m2) return 0; // 平凡情况
	if(n1 == m2 && m1 *b == n2 *a) return 1;
	if(n2 == m1 && m2 *a == n1 *b) return 1;
	if(n1 == n2 && m1 *b == m2 * a) return 1;
	if(m1== m2 && n1 * b == n2*a) return 1;
	return 0;

}

int main(){
	int a = 1, b = 1;
	for(int i = 11; i < 99; i++){
		for(int j = i+1; j< 100; j++){
			if(check(i, j)){
				a *= i;
				b *= j;
			}
		}
	}
	int g = gcd(a, b);
	cout << b/g << endl;
	return 0;
}
