#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node* head=NULL;
struct node* current=NULL;
int alive;

void insertNode(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
        current=newnode;
    }
    else{
        newnode->next=head;
        current->next=newnode;
        current=current->next;
    }
    
}
void printNode()
{
    struct node*temp=head;
    printf("%d->",temp->data);
    temp=temp->next;
    while(temp!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double n;
    scanf("%lf",&n);
    alive=n;
    for(double i=1;i<=n;i++)
    {
        insertNode(i);
    }
    // printNode();
   struct node*killer=head;
    while(alive!=1)
    {
        current=killer->next;
        killer->next=killer->next->next;
        free(current);
        killer=killer->next;
        alive--;
    }
    printf("The last alive soldier is %d",killer->data);
    
    
    return 0;
}
