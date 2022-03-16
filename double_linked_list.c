#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data,Node* prev,Node* curr){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = prev;
    newNode->next = curr;
    return newNode;
}

void prependNode(struct Node* head,int data){
    struct Node* newNode = createNode(data,NULL,NULL);
    if(head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void appendNode(struct Node* head,int data){
    struct Node* temp = head;
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

int main(){
    //TODO: Test it
    return 0;
}
