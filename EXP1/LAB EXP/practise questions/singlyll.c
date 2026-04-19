#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=NULL;
    struct node *newnode;
    int value;
    printf("");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL){
        newnode->next=head;

    }
}