#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *arr;
    int count;
    int capacity;
    int heap_type;
} Heap;

Heap *createHeap(int capacity,int heap_type){
    Heap *h = (Heap*)malloc(sizeof(Heap));

    h->heap_type = heap_type;
    h->count = 0;
    h->capacity = capacity;
    h->arr = (int*)malloc(capacity * sizeof(int));

    return h;
}
void heapify_bottom_top(Head *h,int index){
    int temp;
    int parent_node = (index - 1) / 2;

    if(h->arr[parent_node] < h->arr[index])
        return;
    temp = h->arr[parent_node];
    h->arr[parent_node] = h->arr[index];
    h->arr[index] = temp;
    heapify_bottom_top(h,parent_node);
}
void heapify_top_bottom(Head *h,int parent_node){
    int left = parent_node * 2 + 1;
    int right = parent_node * 2 + 2;
    int min;
    int temp;

    if(left >= h->count || left < 0)
        left = -1;
    if(right >= h->count || right < 0)
        right = -1;

    if(left != -1 && h->arr[left] < h->arr[parent_node])
        min = left;
    else
        min = parent_node;

    if(right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if(min != parent_node){
        temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;

        heapify_top_bottom(h, min);
    }
}
int PopMin(Heap *h){
    int pop;

    pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    heapify_top_bottom(h,0);
    return pop;
}
void insert(Heap *h, int key){
    if(h->count > h->capacity)
        return;

    h->arr[h->count] = key;
    heapify_bottom_top(h,h->count);
    h->count++;
}

