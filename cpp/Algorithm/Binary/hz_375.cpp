#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct student {
	int idx, c, m, e, total;
} Student;

bool cmp(const Student &a, const Student &b){
	if(a.total == b.total){
		if(a.c == b.c){
			return a.idx < b.idx;
		}else{
			return a.c > b.c;
		}
	}else{
		return a.total > b.total;
	}
}

int main(){
	int n;
	cin >> n;
	Student *stu = (Student *)malloc(sizeof(Student) * n);
	for(int i = 1; i <= n; i++){
		cin >> stu[i-1].c >> stu[i-1].m >> stu[i-1].e;
		stu[i-1].idx = i;
		stu[i-1].total = stu[i-1].c + stu[i-1].m + stu[i-1].e;
	}
	sort(stu, stu+n, cmp);
	for(int i = 0; i < 5; i++){
		cout << stu[i].idx << ' ' << stu[i].total << endl;
	}
	free(stu);
	return 0;
}
