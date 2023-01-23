#include<stdio.h>
#include<stdlib.h>
/*#define swap(a, b) { \
	__typeof(a) __tmp; \
	__tmp = a; a = b; b = a; \
}*/

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

typedef struct Heap{
	int *data;
	int len;
	int size;
} Heap;

Heap * initHeap(int cap){
	Heap * h = (Heap *)malloc(sizeof(Heap));
	h->data = (int*)malloc(sizeof(int) * cap);
	h->len = 0;
	h->size = cap;
	return h;
}

void freeHeap(Heap * h){
	if(!h)
		return;
	free(h->data);
	free(h);
	return;
}

int isEmpty(Heap *h){
	return (!h) || (!h->len);
}

int push(Heap * h, int val){
	if (!h)
		return 0;
	if (h->len == h->size)
		return 0;
	h->data[h->len] = val;
	int idx = h->len;
	while(idx > 0 && h->data[idx] > h->data[(idx-1)/2]){
		swap(&h->data[idx], &h->data[(idx-1)/2]);
		idx = (idx-1)/2;
	}
	h->len++;
	return 1;


}

void downAdj(int *arr, int idx, int len){
	while(2*idx+1 < len){
		int tmp = idx, l=idx*2+1, r=idx*2+2;
		if (arr[l] > arr[tmp])
			tmp = l;
		if (r < len && arr[r] > arr[tmp])
			tmp = r;
		if (tmp == idx)
			break;
		swap(&arr[idx], &arr[tmp]);
		idx = tmp;
	}
	return ;
}


int pop(Heap *h){
	int ret = h->data[0];
	h->data[0] = h->data[h->len-1];
	h->len--;

	downAdj(h->data, 0, h->len);
	return ret;

}

int main(){
	int count[4], u, q;
	Heap * heapArray[4];
	for(int i = 0; i < 4; i++){
		scanf("%d", count+i);
		heapArray[i] = initHeap(count[i]);
	}
	for(int i = 0; i <4; i++){
		for(int j = 0; j < count[i]; j++){
			scanf("%d", &u);
			push(heapArray[i], u);
		}
	}
	scanf("%d", &q);
	double value, tmp;
	for(int i=0; i < q; i++){
		value = 0.0;
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		value += pop(heapArray[0]); // 仅需一个守门员
//		printf("@ %lf\n", value);
		for(int j = 0; j < x; j++){
			tmp = pop(heapArray[1]); // 后卫
			value += tmp;
//			printf("@@ %lf\n", tmp);
		}
		for(int j = 0; j < y; j++){
			tmp =  pop(heapArray[2]); // 中场
			value += tmp;
//			printf("@@@ %lf\n", tmp);
		}
		for(int j = 0; j < z; j++){
			tmp = pop(heapArray[3]); // 前锋
			value += tmp;
//			printf("@@@@ %lf\n", tmp);
		}
		printf("%.2lf\n", value/11.0);

	}

	for(int i = 0; i < 4; i++){
		freeHeap(heapArray[i]);
	}
	return 0;
}

