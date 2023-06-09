#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main (){

    //head ptr pointing to the node its self
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    //accessing the node using the created pointer head
    head->data = 45;
    head->link = NULL;

    printf("%d",head->data);
    return 0;

}