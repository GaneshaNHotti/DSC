#include<stdio.h>
#include<stdlib.h>
int i=0;
typedef struct node{
	int data;
	struct node *link;
};
struct node *start=NULL, *ptr, *temp,*cur,*prev,*next;

void insert_beg(){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data.\n");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else{
		temp->link=start;
		start=temp;
	}
}

void display(){
	if(start==NULL){
		printf("Linked list is empty.\n");
	}
	else{
		ptr=start;
		while(ptr!=NULL){					
			printf("%d-->", ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
	}
}

void dis()
{
	if(start==NULL)
	printf("Empty");
	else
	for(ptr=start;ptr!=NULL;ptr=ptr->link)
	printf("%d-->",ptr->data);
}

void reverse()
{
    if(start != NULL)
    {
        prev = start;
        cur = start->link;
        start = start->link;
		prev->link = NULL; 
        while(start != NULL)
        {
            start = start->link;
            cur->link = prev;
		    prev = cur;
            cur = start;
        }
        start = prev;
        display();
        }
}


void main(){
	int ch;
	while(1){
		printf("\nEnter your choice.\n");
		printf("1. Insert_Beg\n2. Display\n3.Reverse\n4. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert_beg();
				break;
			case 2: display();
				break;
			case 3:reverse();
				break;
			case 4: exit(0);
			default: printf("Invalid choice.\n");
		}
	}
}
