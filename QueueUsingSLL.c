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
    printf("enter the data\n");
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

void deletebeg()
{
    struct node *p ;

    if(start == NULL)
        printf("empty\n");

    p = start;


    if(p->link == NULL)
    {
        start = p->link;
        free(p);
    }
    else
    {
        start = p->link;
        p->link = NULL;
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
        printf("1.Insert\n2.Display\n3.Delete\n4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insertend();
                     break;
            case 2 : display();
            		break;
            case 3 : deletebeg();
                     break;
            case 4: exit(0);
        }
    }
}
