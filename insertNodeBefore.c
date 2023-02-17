#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* next;
};

struct node* createNode(int data, struct node* next){
struct node* Node = (struct node*)malloc(sizeof(struct node));
Node->data = data;
Node->next = next;
return Node;
}

void addNode(struct node** head, int data) {
struct node* currentNode = *head;
if(currentNode == NULL) {
*head = createNode(data, NULL);
return;
}
while(currentNode->next != NULL) {
currentNode = currentNode->next;
}
currentNode->next = createNode(data, NULL);
}

void traverse(struct node* head) {
struct node* itr = head;
while(itr != NULL) {
printf("%d ", itr->data);
itr = itr->next;
}
}

void insertNodeBefore(struct node** head, int data, int insertData) {
struct node* currentNode =  *head;
struct node* temp = NULL;
struct node* newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = insertData;
newNode->next = NULL;

while(currentNode->data != data) {
temp = currentNode;
currentNode = currentNode->next;
}
temp->next = newNode;
newNode->next = currentNode;
}

int main()
{
struct node* head = NULL;
addNode(&head, 10);
addNode(&head, 20);
addNode(&head, 30);
insertNodeBefore (&head, 20, 17);
traverse(head);
    return 0;
}