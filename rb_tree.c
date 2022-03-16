#include <stdio.h>
#include <stdlib.h>

#define RED 'R'
#define BLACK 'B'

#define COUNT 10

typedef struct Node {
    int key;
    char color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

struct Node T_Nil_Node;
Node* T_Nil = &T_Nil_Node;

Node* Root = NULL;

Node* newNode(int key)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->color = RED;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
}

void rotateLeft(Node** t,Node* x){
    Node *y = x->right;
    x->right = y->left;
    if(y->left != T_Nil)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == T_Nil)
        *t = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rotateRight(Node** t,Node* y)
{
    Node *x = y->left;
    y->left = x->right;
    if(x->right != T_Nil)
        x->right->parent = y;

    x->parent = y->parent;
    if(y->parent == T_Nil)
        *t = x;
    else if(y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}
void redBlackInsertFixup(Node** Root,Node* New)
{
    Node* temp;
    while(New->parent->color == RED){
        if(New->parent == New->parent->parent->left){
            temp = New->parent->parent->right;
            if(temp->color == RED){
                New->parent->color = BLACK;
                temp->color = BLACK;
                New->parent->parent->color = RED;
                New = New->parent->parent;
            }
            else{
                if(New == New->parent->right){
                    New = New->parent;
                    rotateLeft(Root, New);
                }
                New->parent->color = BLACK;
                New->parent->parent->color = RED;
                rotateRight(Root, New->parent->parent);
            }
        }
        else {
            temp = New->parent->parent->left;
            if(temp->color == RED){
                New->parent->color = BLACK;
                New->color = BLACK;
                New->parent->parent->color = RED;
                New = New->parent->parent;
            }
            else{
                if(New == New->parent->left){
                    New = New->parent;
                    rotateRight(Root, New);
                }
                New->parent->color = BLACK;
                New->parent->parent->color = RED;
                rotateLeft(Root, New->parent->parent);
            }
        }
    }
    Root[0]->color = BLACK;
}
void redBlackInsert(Node** T,int key){
    Node* z = newNode(key);
    Node* y = T_Nil;
    Node* x = *T;
    
    while(x != T_Nil){
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if(y == T_Nil)
        *T = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;

    //Init z as a red leaf
    z->left = T_Nil;
    z->right = T_Nil;
    z->color = RED;

    // Ensure the Red-Black property is maintained
    redBlackInsertFixup(T,z);
}

#define MAX(a,b) (((a)>(b))?(a):(b))

int height(Node* Root){
    int h = 0;

    if(Root != NULL){
        if(Root == T_Nil)
            h = 1;
        else {
            int leftHeight = height(Root->left);
            int rightHeight = height(Root->right);
            h = MAX(leftHeight, rightHeight) + 1;
        }
    }
}
