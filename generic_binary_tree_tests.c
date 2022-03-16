#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.c"
#include "acutest.h"
//insert_tree(tree **l,void* data,size_t data_size,tree *parent)
//traverse_tree(tree *l,void (*proccess_item)(void*))
//search_tree(tree **l,int (*compare)(void*,void*),void* data)
//find_minimum(tree *l)
//
int compare(const void * a,const void * b){    
    return *(int*)a - *(int*)b;
}
void insert_test(){
    int numbers[10];
    int n = 0;
        //(rand() % 3657791);
    //numbers[0] = n;
    struct tree* top = malloc(sizeof(struct tree));
        //create_tree(&n,sizeof(int));    
    for(int i = 0; i < 10;i++){
        n = (rand() % 3657791);
        numbers[i] = n;
        insert_tree(&top,top,&n,sizeof(int),compare_int);
    }
    for(int i = 0;i < 10;i++){ 
        tree* t = search_tree(top,compare,&numbers[i]);
        TEST_CHECK(t != NULL);
    }
}
TEST_LIST = {
    { "insert test", insert_test },
    { NULL, NULL }
};
