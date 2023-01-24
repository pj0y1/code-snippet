#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	int t, p, tmp;
	vector<int> time;
	vector<int> ppl;
	vector<set<int> >country;
	for(int i = 0; i< n; i++){
		scanf("%d%d", &t, &p);
		time.push_back(t);
		ppl.push_back(p);
		country.push_back(set<int>());
		for(int j = 0; j < p; j++){
			scanf("%d", &tmp);
			country[i].insert(tmp);
		}

		int prev = i;
		while(prev >= 0 && time[i] - time[prev] < 86400)
			prev--;
		prev++;
		set<int> tmp;
		for(int j=prev; j <= i; j++){
			for(auto it = country[j].begin(); it != country[j].end(); it++){
				tmp.insert(*it);
			}
		}
		printf("%lu\n", tmp.size());

	}

	return 0;
}
