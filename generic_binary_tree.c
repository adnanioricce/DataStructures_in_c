#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct tree {
    void* data;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree ;
struct tree *create_tree(const void* data,size_t data_size){
    struct tree *p = malloc(sizeof(struct tree));
    if(!p){
      fprintf(stderr,"malloc() fail\n");
      return NULL;
    }
    p->data = malloc(data_size);
    if(!p->data){
        fprintf(stderr,"malloc() fail\n");
        free(p);
        return NULL;
    }
    memcpy(p->data,data,data_size);
    p->left = p->right = NULL;
    p->parent = NULL; 
    return p;
}
bool is_empty_tree(struct tree *t){
    if(t == NULL)
        return true;
    if(t->data == NULL && t->left == NULL && t->right == NULL && t->parent == NULL)
        return true;
    return false;        
}
struct tree *search_tree(struct tree *l,int (*compare)(const void *,const void *),void* data){
    printf("%p\n",l);
    if(is_empty_tree(l)){
        return NULL;
    }
    int comparison = compare(l->data,data);
    if(comparison == 0){
        return l;
    }
    
    if(comparison == -1){
        return search_tree(l->left,compare, data);       
    }
    else {
        return search_tree(l->right,compare, data);
    }
}
tree *find_minimum(tree *t){
    tree *min;
    if(t == NULL){
        return NULL;
    }

    min = t;
    while(min->left != NULL){
        min = min->left;
    }
    return min;
}
void traverse_tree(tree *l,void (*process_item)(const void*)){
    if(is_empty_tree(l))
        return;
    traverse_tree(l->left,process_item);
    process_item(l->data);
    traverse_tree(l->right,process_item);
}
void insert_tree(struct tree **l,struct tree *parent,const void *data,size_t data_size,int (*compare)(const void*,const void*)){
    if(!is_empty_tree(*l)){
        struct tree *p = create_tree(data,data_size);
        int* point = ((int*)data);
        printf("%d\n",*(point));
        p->parent = parent;
        *l = p;
        return;
    }
    tree** left = &((*l)->left);
    tree** right = &((*l)->right);
    const void* lhs = (*l)->data;
    const void* rhs = data;
    if(compare(lhs,rhs) == -1){
        insert_tree(left, *l, data, data_size, compare);
    }
    else {
        insert_tree(right, *l, data, data_size, compare);
    }
}
int compare_int(const void* a,const void* b){
    if(a == NULL)
        return 1;
    if(b == NULL)
        return -1;    
    int* lhs = ((int*)a);
    int* rhs = ((int*)b);
    if((*lhs) > (*rhs)){
        return 1;
    }
    else if((*lhs) < (*rhs)){
        return -1;
    }
    else {
        return 0;
    }
}

