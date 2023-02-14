#include <stdio.h>
#include<stdlib.h>

//defining the node structure 
struct node {
int data;
struct node* next;
};

//function to create a node
struct node* createNode(int data, struct node* next) {
  struct node* Node = (struct node*)malloc(sizeof(struct node));
  Node->data = data;
  Node->next = next;
  return Node;
}

// Function to add a new node to the end of the linked list
void add_node(struct node** head, int data) {
    // Allocate memory for the new node variable in heap memory
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    // Initialize the new node's data and next pointer
    new_node->data = data;
    new_node->next = NULL;
    
    // If the linked list is empty, make the new node the head node
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    // Traverse to the last node of the linked list
    struct node* last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    
    // Add the new node to the end of the linked list
    last_node->next = new_node;
}

//Traversing the linked list
void traverse(struct node* head) {
  //making a current node variable and assigning it to head
    struct node* current_node = head;
  //traversing the whole linked list
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }  
}

int main(void) {
  //head pointer
  struct node* head = NULL;

  //1. array to linked list conversion
  int arr[] = {10,20,30,40,50,34,52};
  
  for(int i=0; i<sizeof(arr)/sizeof(arr[i]); i++) {
    add_node(&head, arr[i]);
  }

  //2. traversing the linked list
  traverse(head);
  return 0;
}
