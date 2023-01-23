#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node * next;
} Node;

Node * initNode(int val){
	Node * n = (Node *)malloc(sizeof(Node));
	n->val = val;
	n->next = NULL;
}

Node* insert(Node * head, Node * node){
	node->next = head;
	return node;
}

void freeNode(Node * head){
	Node *del_node, *cur_node = head->next;
	while(cur_node->next != head){
		del_node = cur_node;
		cur_node = cur_node->next;
		free(del_node);
	}
	free(head);
	return;
}


int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int i = m;
	Node * head = initNode(i);
	Node * end = head;
	Node * cur;
	while(--i){
		Node * new_node = initNode(i);
		head = insert(head, new_node);
	}
/*	Node * tmp = head;
	for(int k=0; k < m; k++){
		printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
*/
	end->next = head;
//	printf("%d %d\n", end->val, end->next->val);
	cur = end;
	Node * prev;
	while(m > 0){
		for(int j = 0; j < n; j++){
			prev = cur;
			//printf("cur val %d\n", cur->val);
			cur = cur->next;
		}
		printf("%d", cur->val);
		m > 1 && printf(" ");
		prev->next = cur->next;
		free(cur);
		cur = prev;
		m--;
	}
	printf("\n");
	return 0;
}
