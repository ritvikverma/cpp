//
//  linkedList.c
//  LinkedList
//
//  Created by Ritvik Verma and Abhinandan Vellanki on 23/11/2018.
//  Copyright © 2018 Ritvik Verma and Abhinandan Vellanki. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node Node;

// Display the list
void printList(Node *head_ref) { //printList function with function parameter *head_ref for the pass-by-reference of head pointer
    Node *sample = head_ref; //An arbitrary function for traversing through the list
    printf("[ ");
    while(sample!=NULL)//Traversing till we reach the end, that is, the end pointer that points to NULL
    {
        printf("%d ", sample->data);//In every iteration, we print the data that the current node contains.
        sample= sample->link;//Move to the link node for repeat and printing the link node data.
    }
    printf("]");
    
}

// Insert data into a sorted list
void sortedInsert(Node **head_ref, int data)
{
    Node *n =(Node*) malloc(sizeof(Node)) ;//Allot memory for the new node with the size of "Node"
    n->data = data;//The node to be inserted has the value that is passed in the parameters of the function
    n->link = NULL;
    Node *i;
    i = *head_ref;
    if(*head_ref==NULL || (*head_ref)->data >= n->data){//If list is empty or head's value is greater than new value
        n->link = *head_ref;//Insert at head
        (*head_ref) = n;//Make new head
    }
    
    
    else{
        
        while(i->link != NULL && i->link->data < data){//While the next data is lesser than the current data
            i = i->link;
        }
        n->link = i->link;//New node points to the next node's next
        i->link = n;//Next node points to new node
    }
    
    
}

// Reverse nodes in a linked list
void reverse(Node **head_ref) {
    // Please implement this function
    Node *current=*head_ref;//Create a traversal node for moving through the list
    Node *link=NULL;//To store the link of the current node in question
    Node *prev=NULL;//To store the last node in the traversal while looking at the current node
    while(current!=NULL)
    {
        link=current -> link;//Stores the next value for swap
        current -> link=prev;//Changes the next value to the previous value
        prev=current;//Makes the previous node the current node
        current=link;//Make the current node the next node
    }
    *head_ref=prev;//Goes to the "next" node
}

//Search for a specific element in the LinkedList
void searchForElement(Node *head_ref, int n)
{
    bool found = false;
    Node *sample = head_ref; //An arbitrary function for traversing through the list
    while(sample!=NULL)//Traversing till we reach the end, that is, the end pointer that points to NULL
    {
        if(sample->data == n)
        {found = true;}
        sample = sample->link;
    }
    if(!found)
        printf("%d was not found in the list\n", n);
    else
        printf("%d was found in the list\n", n);
    
    
}



void PrintSum(Node *head_ref)
{
    Node *sample = head_ref;
    int sum = 0;
    while(sample!=NULL)
    {
        sum+=(sample->data);
        sample = sample->link;
    }
    printf("\nSum of elements is: %d", sum);
}


// Main program
int main() {
    int n;
    Node *head = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n;  i++)
    {
        int x;
        
        scanf("%d", &x);
        sortedInsert(&head, x);
    }
    
    printf("Original List: ");
    printList(head);
    int element;
    PrintSum(head);
    reverse(&head);
    printf("\nList after reversing the data: ");
    printList(head);
    printf("\n");
    printf("Enter element to be found: ");
    scanf("%d", &element);
    searchForElement(head, element);
    return 0;
}
