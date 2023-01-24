#include <iostream>
#include <string>

using namespace std;

string l, r;

int main(){
	cin >> l >> r;
	int w1 = l.size(), w2 = r.size();
	long long ans = 0;
	int w = w1;
	while(w <= w2){
		for(char i = '1'; i <= '9'; i++){
			string trailing_zero(w, '0');
			trailing_zero[0] = i;
			if ((trailing_zero.size() > w1 || trailing_zero >= l) &&(trailing_zero.size() < w2 || trailing_zero <= r)){
				ans++;
			}
			string tmp(w, i);
			for(int p=w-1; p > 0; p--){
				tmp[p] = '0';
				if ((tmp.size() > w1 || tmp >= l) &&(tmp.size() < w2 || tmp <= r)){
					ans += 1;
				}
				tmp[p] = i;
			}
			for(char j = '1'; j <= '9'; j++){
				if( j == i) continue;
				for(int p = w-1; p >= 0; p--){
					tmp[p] = j;
					if ((tmp.size() > w1 || tmp >= l) &&(tmp.size() < w2 || tmp <= r)){
						ans += 1;
					}
					tmp[p] = i;
				}
			}
		}
		w++;
	}
	printf("%lld\n", ans);
	return 0;
}
