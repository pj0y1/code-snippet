#include <cstdio>
#include <map>
#include <vector>
#include <unordered_set>

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	int t, p, tmp;
	int last = 0;
	vector<int> time(n, 0);
	vector<unordered_set<int> > country(n, unordered_set<int>());
	map<int, int> counter;


	for(int i = 0; i< n; i++){
		scanf("%d%d", &t, &p);
		time[i] = t;
		for(int j = 0; j < p; j++){
			scanf("%d", &tmp);
			country[i].insert(tmp);
			counter[tmp]++;
		}

		int prev = i;
		while(prev >= 0 && time[i] - time[prev] < 86400)
			prev--;
		prev++;
		for(int j=last; j < prev; j++){
			for(auto it = country[j].begin(); it != country[j].end(); it++){
				counter[*it]--;
			}
		}
		last = prev;
		int total = 0;
		for(auto it = counter.begin(); it != counter.end(); it++){
			if(it->second > 0) total++;
		}
		printf("%d\n", total);

	}

	return 0;
}
