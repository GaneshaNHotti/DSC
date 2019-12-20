#include<stdio.h>
#define SIZE 50
int top = -1,stack[SIZE],item;
//push
void push()
{
    //overflow check
    if(top == SIZE-1)
        printf("OVERFLOW!!!");
    else
    {
        printf("Enter data \t:");
        scanf("%d",&item);
        stack[++top] = item;
    }

}
//pop
void pop()
{
    //if Underflow
    if(top == -1)
        printf("UNDERFLOW");
    else
    {
        printf("Deleted element is : %d",stack[top--]);
    }
}
//display
void display()
{
    int i;
    printf("\n");
    for(i = top; i>-1; i--)
    {
        printf("%d\n",stack[i]);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\t\t\tStack\n1.Push\n2.Pop\n3.Display\n4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: exit(0);
            default: printf("invalid input try again");
        }
    }
}
