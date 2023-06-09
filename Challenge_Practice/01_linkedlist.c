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

    //creating a second node to form a linked listed
    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;

    //linking the first node to the second node
    head->link = current;

    //creating third node
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;

    //Linking the 3rd node to the second node

    head->link->link = current;

    //creating a forth node
    current = malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;

    //linking the forth node to the 3rd node

    head->link->link->link = current;
    
    printf("Node one data %d\n",head->data);
    printf("Node two data %d\n",head->link->data);
    printf("Node three data %d\n",head->link->link->data);
    printf("Node Four data %d\n",head->link->link->link->data);
    return 0;

}