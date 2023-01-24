#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


struct student {
	string name;
	int avg, cla, paper, cnt, sum;
	char off, west;
};

student stu[105];
int func(int x){
	int t = 0;
	if(stu[x].avg > 80 && stu[x].paper > 0) t += 8000;
	if(stu[x].avg > 85 && stu[x].cla > 80) t += 4000;
	if(stu[x].avg > 90) t += 2000;
	if(stu[x].avg > 85 && stu[x].west  == 'Y') t += 1000;
	if(stu[x].cla > 80 && stu[x].off  == 'Y') t += 850;
	return t;
}

bool cmp(const student &a, const student &b){
	if(a.sum == b.sum){
		return a.cnt < b.cnt;
	}
	return a.sum > b.sum;
}


int main(){
	int n, ans = 0;
	cin >> n;
	for(int i=0; i < n; i++){
		cin >> stu[i].name >> stu[i].avg >> stu[i].cla >> stu[i].off >> stu[i].west >> stu[i].paper;
		stu[i].cnt = i;
		stu[i].sum = func(i);
		ans += stu[i].sum;
	}
	sort(stu, stu+n, cmp);
	cout << stu[0].name << endl << stu[0].sum << endl << ans << endl;
	return 0;
}
