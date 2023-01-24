#include <iostream>
#include <cstring>

using namespace std;

char s1[1005];
char s2[1005];

int n1[1005], n2[1005], ans[2005];

int main(){
	cin >> s1 >> s2;
	n1[0] = strlen(s1), n2[0] = strlen(s2);
	for(int i=1; i <= n1[0]; i++){
		n1[i] = s1[n1[0]-i] - '0';
	}
	for(int i=1; i <= n2[0]; i++){
		n2[i] = s2[n2[0]-i] - '0';
	}
	int carry = 0;
	ans[0] = n1[0] + n2[0] -1;
	for(int i=1; i <= n1[0] || carry; i++){
		for(int j =1; j <= n2[0] || carry; j++){
			int tmp = n1[i] * n2[j] + carry;
			ans[i+j-1] += tmp;
			if (ans[i+j-1] > 9){
				carry = ans[i+j-1]/10;
				ans[i+j-1] %= 10;
			}
			else
				carry = 0;
			ans[0] = max(ans[0], i+j-1);
		}
	}
	for(int i = ans[0]; i > 0; i--){
		cout << ans[i];
	}
	cout << endl;
	return 0;

}
