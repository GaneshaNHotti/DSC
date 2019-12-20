// FIFO (Insert at end and deletion at beg)
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
int front= -1,rear =-1,queue[SIZE],item;
//insert
void insert()
{
    
    if(rear == SIZE-1)
        printf("OVERFLOW\n");
    else
    {
        printf("Enter data\t:");
        scanf("%d",&item);
        if(front ==-1 && rear == -1) // IMP!
        {
            front = rear = 0;
            queue[rear] = item;
        }
        else
            queue[++rear] = item;
    }
}
//delete
void delete()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }  
    else
    {
        printf("Deleted item is %d \n",queue[front++]);
    }
    
}
//display
void display()
{
    int i;
    if(rear==-1)
    printf("Empty\n");
    else
	{
	for(i = front; i <= rear; i++)
        printf("%d\t",queue[i]);
    printf("\n");
	}
}
void main()
{
    printf("\t\t\t QUEUE\n");
    int ch;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);     
        switch (ch)
        {
        case 1: insert();
            break;
        case 2: delete();
            break;
        case 3: display();
            break;
        case 4:exit(0);
        default: printf("INVALID INPUT");
            break;
        }  
    }
}
