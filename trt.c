#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;
struct Node *tail=NULL;

insertfromBeg(int val)
{
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=newNode->prev=NULL;
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        printf("%d inserted\n",val);
    }
}

insertfromend(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = newNode->prev = NULL;
    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        printf("%d inserted\n", val);
    }
}

void deletefrombeg(){
    if(head==NULL)
    {
        printf("List is Empty..\n");
        return;
    }
    struct Node *temp= head;
    printf("%d is deleted",temp->data);
    head= head->next;
    if(head!=NULL)
    head->prev=NULL;
    else
    tail=NULL;
    free(temp);
}

void deletefromend()
{
    if (tail == NULL)
    {
        printf("List is Empty..\n");
        return;
    }
    struct Node *temp = tail;
    printf("%d is deleted", temp->data);
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;
    free(temp);
}