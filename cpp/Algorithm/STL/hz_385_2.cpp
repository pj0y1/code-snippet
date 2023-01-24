#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	int t, p, tmp;
	vector<int> time(n, 0);
	vector<unordered_set<int> >country(n);
	for(int i = 0; i< n; i++){
		scanf("%d%d", &t, &p);
		time[i] = t;
		for(int j = 0; j < p; j++){
			scanf("%d", &tmp);
			country[i].insert(tmp);
		}

		int prev = i;
		while(prev >= 0 && time[i] - time[prev] < 86400)
			prev--;
		prev++;
//		printf("prev=%d, time[i]=%d\n", prev, time[i]);
		unordered_set<int> tmp;
		for(int j=prev; j <= i; j++){
			for(auto it = country[j].begin(); it != country[j].end(); it++){
				tmp.insert(*it);
			}
		}
		printf("%lu\n", tmp.size());

	}

	return 0;
}
