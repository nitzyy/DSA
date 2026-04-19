#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* insert_m(struct node *head, int value, int pos){
    struct node *temp, *newnode;
    int i;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    temp=head;
    for (i=0;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
};
