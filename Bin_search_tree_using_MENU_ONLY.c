#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *root=NULL,*ptr,*parent;

void create()
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data :- ");
    scanf("%d", &temp->data);
    temp->rlink=NULL;
    temp->llink=NULL;

    if(root==NULL)
        root=temp;
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(ptr->data==temp->data)
            {
                printf("Node exist !!");
                return;
            }
            else if(temp->data < ptr->data)
                ptr=ptr->llink;
            else
                ptr=ptr->rlink;
        }
        if(parent->data < temp->data)
            parent->rlink=temp;
        else
            parent->llink=temp;
    }
}
void display()
{
    printf("The inorder traversal of the tree is :\t");
    inorder(root);

}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d\t",tree->data);
        inorder(tree->rlink);
    }

}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Exit\n");
        printf("Enter your choice :- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : display();
                     break;
            case 3 : exit(0);
        }

    }

}
