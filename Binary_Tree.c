#include<stdio.h>
#include<stdlib.h>
//define node
typedef struct node
{
    int data;
    struct node *llink,*rlink; 
}node;
//initilize pointers
node *root=NULL,*temp,*ptr;

//is left node
int is_left_node(node *tree)
{
    int ch;
    printf("\nDo you want to enter a left node : %d\t[Yes : 1 or No : 0] \t :",tree->data);
    scanf("%d",&ch);
    if(ch == 1)
        return 1;
    else
        return 0;
}
//is right node
int is_right_node(node *tree)
{
    int ch;
    printf("\nDo you want to enter a right node : %d\t[Yes : 1 or No : 0 ]\t :",tree->data);
    scanf("%d",&ch);
    if(ch == 1)
        return 1;
    else
        return 0;
}
//create normal tree
void create_Binary_Tree(node *tree)
{
    if(is_left_node(tree) == 1)
    {
        //allocate memory
        temp = (node*)malloc(sizeof(node));
        printf("\nEnter data :");
        scanf("%d",&temp->data);
        //linking
        tree->llink = temp;
        // now making this new node as root for the subtree
        create_Binary_Tree(temp); 
    }
    else
        tree->llink = NULL;  //since no left link present
    if(is_right_node(tree) == 1)
    {
        temp = (node*)malloc(sizeof(node));
        printf("\nEnter Data :");
        scanf("%d",&temp->data);
        //linking
        tree->rlink = temp;
        // now making this new node as root for the subtree
        create_Binary_Tree(temp);
    }
    else
        tree->rlink = NULL; // since no right link present
}
//DISPLAY
void inorder_display(node *tree)
{
    if(tree!=NULL)
    {
        inorder_display(tree->llink);        //L
        printf("%d -- ",tree->data);         //N
        inorder_display(tree->rlink);        //R
    }
}
void preorder_display(node *tree)
{
    if(tree!=NULL)
    {
        printf("%d -- ",tree->data);          //N
        preorder_display(tree->llink);        //L         
        preorder_display(tree->rlink);        //R
    }
}
void postorder_display(node *tree)
{
    if(tree!=NULL)
    {
        postorder_display(tree->llink);        //L
        postorder_display(tree->rlink);        //R
        printf("%d -- ",tree->data);           //N
    }
}
//main
void main()
{
    printf("\n\t\tBINARY TREE\n");
    root = (node*)malloc(sizeof(node));
    printf("\nEnter Data :");
    scanf("%d",&root->data);
    create_Binary_Tree(root);

    printf("\n\t\tDISPLAY\n");
    printf("\n\t\t\tINORDER\n"); 
    inorder_display(root);
    printf("\n\t\t\tPOSTORDER\n"); 
    postorder_display(root);
    printf("\n\t\t\tPREORDER\n"); 
    preorder_display(root);

    
}
