#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
}Node;
struct Node* head;
void Insert(struct Node* previous,int x)
{
    struct Node* temp1 = NULL;
        temp1 = ( struct Node*)malloc(sizeof(Node));
        temp1->data=x;
        temp1->next=NULL;
        if(previous==NULL)
        {
            temp1->next = head;
            head = temp1;
            previous=temp1;
        }
        else
        {
            temp1->next = previous;
            previous = temp1;
        }
}
void Print()

{
    struct Node* temp1 = head;
    while(temp1 != NULL)
    {
        printf(" %d",temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = NULL;
    head = NULL; //empty
    printf("how many numbers\n");
    int n,i,x;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the number\n");
        scanf("%d",&x);
        Insert(head->next,x);
        Print();

    }
}
