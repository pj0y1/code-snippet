#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 100
#define MAX_LEN 2000

char name[MAX_NAME_LEN] = {0};
char another_name[MAX_NAME_LEN] = {0};
char * candidate[MAX_LEN+5] = {0};

typedef struct DisjointSet{
	int *data;
	int *rank;
	int len;
} DisjointSet;

DisjointSet * init(int len){
	DisjointSet * d = (DisjointSet *)malloc(sizeof(DisjointSet));
	d->data = (int*)malloc(sizeof(int)*len);
	d->rank = (int *)malloc(sizeof(int)*len);
	d->len = len;
	for(int i=0; i<len; i++){
		d->data[i] = i;
		d->rank[i] = 1;
	}
	return d;
}

void clean(DisjointSet * d){
	if(!d)
		return;
	free(d->data);
	free(d->rank);
	free(d);
	return;
}

int find_root(DisjointSet *d, int target){
	if(d->data[target] != target)
		d->data[target] = find_root(d, d->data[target]);
	return d->data[target];
}

void merge(DisjointSet *d, int node_a, int node_b){
	int root_a = find_root(d, node_a);
	int root_b = find_root(d, node_b);
	if (root_a != root_b){
		if(d->rank[root_a] > d->rank[root_b]){
			d->data[root_b] = root_a;
			d->rank[root_a] += d->rank[root_b];
		} else {
			d->data[root_a] = root_b;
			d->rank[root_b] += d->rank[root_a];
		}
	}
}

int main(){
	int candidate_count, pair_count;
	scanf("%d %d", &candidate_count, &pair_count);
	DisjointSet * d = init(candidate_count);
	for(int i = 0; i < candidate_count; i++){
		scanf("%s", name);
		int len = strlen(name);
		char *s = (char *)malloc(len+1);
		strncpy(s, name, len+1);
		candidate[i] = s;
	}
	for(int i = 0; i < pair_count; i++){
		int a, b;
		scanf("%s %s", name, another_name);
		for(int j = 0; j < candidate_count; j++){
			if(strcmp(name, candidate[j]) == 0){
				a = j;
				break;
			}
		}
		for(int j = 0; j < candidate_count; j++){
			if(strcmp(another_name, candidate[j]) == 0){
				b = j;
				break;
			}
		}
		merge(d, a, b);
	}
	int qcount;
	scanf("%d", &qcount);
	for(int i = 0; i< qcount; i++){
		
		int a, b;
		scanf("%s %s", name, another_name);
		for(int j = 0; j < candidate_count; j++){
			if(strcmp(name, candidate[j]) == 0){
				a = j;
				break;
			}
		}
		for(int j = 0; j < candidate_count; j++){
			if(strcmp(another_name, candidate[j]) == 0){
				b = j;
				break;
			}
		}
		int ra = find_root(d, a);
		int rb = find_root(d, b);
		if(ra == rb){
			printf("Yes.\n");
		}else{
			printf("No.\n");
		}
	}
	clean(d);
	for(int i = 0; i < candidate_count; i++){
		free(candidate[i]);
	}
	return 0;

}
