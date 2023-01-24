#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node {
	char c; 
	int n;
};

char s[50];
char num[50];


void print(int pos){
	
	for(int i = 0; i <= pos; i++){
		putchar(num[i]);
	}
	putchar(' ');
	putchar('\n');
}

void func(vector<node> &v, int cur, int pos){
	if(cur == v.size()) {
		print(pos);
	}
	if (cur == v.size()-1){	
		for(int i = 1; i <= v[cur].n; i++){
			num[pos+i] =v[cur].c;
			func(v, cur+1, pos+i);
		}
	}else{
		for(int i = 1; i <= v[cur].n; i++){
			num[pos+i] =v[cur].c;
		}
		for(int i = v[cur].n; i>= 1; i--){
			func(v, cur+1, pos+i);
		}
	}

}


int main(){
	scanf("%s", s);
	vector<node> v;
	int pos = 0;
	int i = 0;
	while(s[i]!= 0){
		if(s[i] != s[pos]){
			v.push_back((node){s[pos], i-pos});
			pos = i;
		}
		i++;
	}
	if(pos < i){
		v.push_back((node){s[pos], i-pos});
	}
	func(v, 0, 0);
	return 0;
}
