#include <iostream>
#include <cmath>
using namespace std;

// ans 45228

int width(int n){
	return floor(log10(n))+1;
}

int isComplete(int a, int b, int c){
	int num[10] = {0};
	while(a){
		if (a%10 == 0)
			return 0;
		if(num[a%10] > 0)
			return 0;
		num[a%10] = 1;
		a /= 10;
	}
	while(b){
		if (b%10 == 0)
			return 0;
		if(num[b%10] > 0)
			return 0;
		num[b%10] = 1;
		b /= 10;
	}
	while(c){
		if (c%10 == 0)
			return 0;
		if(num[c%10] > 0)
			return 0;
		num[c%10] = 1;
		c /= 10;
	}
	return 1;
}


int main(){
	int ans = 0, mark[10005] = {0};
	for(int i = 1; i < 99; i++){
		for(int j=i+1; 1; j++){
			int a = width(i), b = width(j), c = width(i*j);
			if(a+b+c > 9)
				break;
			else if (a+b+c == 9){
				if (isComplete(i, j, i*j)){
					if(mark[i*j] == 0){
						ans += i*j;
						mark[i*j] = 1;
					}
					cout << i << " * " << j << " = " << i*j << endl;
				}			
			}
		}
	}
	cout << ans << endl;
}
