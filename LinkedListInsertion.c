#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traversal(struct Node * ptr){
    while(ptr != NULL){
    printf("Elements are: %d\n", ptr->data);
    ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    
    ptr->data = data;
    struct Node *p = head;

    while(p->next != NULL){
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}
    

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while(i != index - 1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 34;
    head->next = second;

    second->data = 59;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 67;
    fourth->next = NULL;

     printf("Linked list before insertion\n");
    traversal(head);
    // head = insertAtFirst(head, 45);
    // head = insertAtIndex(head, 99, 2);
    // head = insertAtEnd(head, 93);
    head = insertAfterNode(head, second, 38);
    printf("Linked list after insertion\n");
    traversal(head);
    return 0;
}