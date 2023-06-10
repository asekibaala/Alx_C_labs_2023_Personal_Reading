#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void print_of_nodes(struct node *head){
    //intializting counter to use for counting 
    int count = 0;
    //checking if recieved head pointer is not NULL
    if(head == NULL){
        printf("Linked List is empty");
    }
    //creating a pointer of type struct node for moving the pointer
    struct node *ptr = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d \n",ptr->data);
        count++;
        //moving ptr to point to next node link 
        ptr = ptr->link;
    }
    printf("There are %d nodes in your linked List\n",count);
    
}

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
    
    print_of_nodes(head);

    return 0;

}