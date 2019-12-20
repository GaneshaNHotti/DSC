#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;

void insertend()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *p;
        p = start;
        while(p->link != NULL)
        {
            p = p -> link;
        }
        p -> link = temp;

    }
}

void deleteend()
{
    struct node *p, *cur;

    if(start == NULL)
        printf("empty\n");

    cur = start;
    p = cur->link;

    if(cur->link == NULL)
    {
        start = cur->link;
        free(cur);
    }
    else
    {
        while(p->link != NULL)
        {
            p = p->link;
            cur = cur->link;
        }
        cur->link = p->link;
        free(p);
    }

}

void display()
{
    struct node *temp;
    temp = start;
    if(start == NULL)
        printf("empty\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}



void main()
{
    int ch;
    while(1)
    {
        printf("1.Push\n2.Display\n3.Pop\n4.Exit\n");
        printf("enter the choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insertend();
                     break;
            case 2 : display();
            		break;
            case 3 : deleteend();
                     break;
            case 4: exit(0);
        }
    }
}
