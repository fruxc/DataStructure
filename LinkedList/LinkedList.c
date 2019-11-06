#include<stdio.h>
#include<stdlib.h>

void insertB();
void insertE();
void display();
void sorting();
void deleteB();
void deleteE();
void deleteP();
void reverse();
void insertBeforeP();
void insertAfterP();
void counting();
void search();
int counter=0;

// A linked list node 
struct Node 
{ 
	int data;
	struct Node *next;
}*temp, *list = NULL, *s, *r, *q, *p;

//menu driven program for insertion deletion and to display linked list
int main()
{
	int ch;
	
	do
	{
		printf("\n Enter Choice :-\n");
		printf("\n 1. Insert at the beginning.\n 2. Insert at the end.\n 3. Insert before a particular node.\n 4. Insert after a particular node.\n 5. Delete at the beginning.\n 6. Delete at the end.\n 7. Delete particular element. \n 8. Display.\n 9. Exit.\n 10. Sort.\n 11. Reversal.\n 12. Search\n 13. Count.\n");

		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertB();
				break;
			case 2:
				insertE();
				break;
			case 3:
				insertBeforeP();
				break;
			case 4:
				insertAfterP();
				break;
			case 5:
				deleteB();
				break;
			case 6:
				deleteE();
				break;
			case 7:
				deleteP();
				break;
			case 10:
				sorting();
				break;
			case 8:
				display();
				break;
			case 9: 
				printf("\n Bye!!!\n");
				exit(0);
				break;
			case 11:
				reverse();
				break;
			case 12:
				search();
				break;
			case 13:
				counting();
				break;
			default:
				printf("\n Invalid Choice\n");
				break;
		}
	}while(ch!=9);
}

void insertB()
{
	int data1;
	if(list==NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
                p->data = data1;	//setting very first element->next to null eg list->data = data1 and list->next = NULL.
                p->next = NULL;
                list = p;

	}
	else
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		printf("\n Enter an element to insert.\n");
		scanf("%d",&data1);
		p->data = data1;
		p->next = list;
		list = p;	//setting new element's next to point to previous element.
	}
}

void insertE()
{
	int data1;
        if(list==NULL)
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
                p->data = data1;        //setting very first element->next to null eg list->data = data1 and list->next = NULL.
                p->next = NULL;
                list = p;

        }
        else
        {
                p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                printf("\n Enter an element to insert.\n");//input.
                scanf("%d",&data1);
		p->data = data1;
                p->next = NULL;         //NULL because it'll be the last element of the linked list.
		q = list;
		while(q->next != NULL)
		{
			q = q->next;	//To check pointer q has reached last location of the linked list.
		}
		q->next = p;		//setting last element to p which will be like adding a new element at the last location.

	}
}

void insertBeforeP()
{
	int data1;
	if(list == NULL)
	{
		printf("\n Linked List is empty.\n");	//if it's empty.
	}
	else
	{
		
		printf("\n Enter element to insert before an element.\n");
		scanf("%d",&data1);						// to search the particular node.
		q = list;
		r = list;
		while(q->data != data1 && q!=NULL)
		{
			r = q;				//storing before data matches pointer in r.
			q = q->next;
		}
		if(q->data == data1)			//if data found
		{
			if(q == list)
			{
				insertB();	//if it's first element
			}
			else
			{
				p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
        	       		printf("\n Enter an element to insert.\n");//input.
		                scanf("%d",&data1);
        	       		p->data = data1;
                		p->next = q;		//setting newly added node->next to searched node
				r->next = p;		//setting before node->next to newly added node p
			}
		}
		else
		{
			printf("\n Element not found.\n");
		}
	}

}

void insertAfterP()
{
        int data1;
        if(list == NULL)
        {
                printf("\n Linked List is empty.\n");    //if it's empty.
        }
        else
        {
                printf("\n Enter element to insert before an element.\n");
                scanf("%d",&data1);                                             // to search the particular node.
                q = list;
		r = list;
                while(q->data != data1 && q!=NULL)
                {
                        q = q->next;
			r = q;				// storing after matching element found node to r
                }
                if(q->data == data1)                    //if data found
                {
			if(q->next == NULL)
			{
				insertE();		//if it's list element
			}
			else
			{
                       		p = (struct Node *)malloc(sizeof(struct Node));//To assign memory location.
                 	       	printf("\n Enter an element to insert.\n");//input.
        	                scanf("%d",&data1);
           			p->data = data1;
				r = q->next;
                        	p->next = r;            //setting newly added node->next to after searched node
                        	q->next = p;            //setting before node->next to newly added node p
			}
                }
                else
                {
                        printf("\n Element not found.\n");
                }
        }

}

void deleteB()
{
	if(list == NULL)
	{
		printf("\n Linked List is empty.\n");		//to check whether it is empty or not
	}
	else
	{
		q = list;
		list = list->next;				//since list is pointing at first location and we're storing it in q and pointing out list to next element. Free q will delocate memeory.
		if(q->next == NULL)
		{
			list = NULL;
		}
		free(q);
		printf("\n Deleted first element.\n");
	}
}

void deleteE()
{
        if(list == NULL)
        {
                printf("\n Linked List is empty.\n");	//to check whether it is empty or not
        }
        else
        {
                q = list;
                while(q->next!=NULL)		//while to point q pointer at the very last location of linked list, we're running it till end.
		{
			r = q;			//r will store previous pointed out location of linked list
			q=q->next;		//to increment q
		}
		r->next=NULL;			//setting previous location's next pointer to NULL since it's very last element so it should point to NULL.
                if(q->next == NULL)
		{
			list = NULL;
		}
		free(q);			// delocating memory of q
                printf("\n Deleted last element.\n");
        }
}

void deleteP()
{
        if(list == NULL)
        {
                printf("\n Linked List is empty.\n");	//to check whether it is empty or not

        }
        else
        {	int data1;				//temporary data
                q = list;				// q to point first location
		printf("\n Enter Data to delete.\n");
		scanf("%d",&data1);			//taking value from the user to search that particular element to delete.

                while(q->data!=data1 && q->next!=NULL)	//to check given input is present in the linked list or not.
		{	
			r = q;                  //r will store previous pointed out location of linked list
                        q=q->next;              //to increment q
		}
		if(q == list)
		{
			deleteB();		//if q is first element
		}
		else if(q->next == NULL)
		{
			deleteE();		//if q is last element
		}
		else if(q->data == data1)		//if given value matches
		{
			r->next = q->next;	//previous next will point to q's next
                	free(q);		//delocating memery of q
                	printf("\n Deleted element :- %d\n",data1);
		}
		else
		{
			printf("\n Element not found.\n");	//if given data doesn't matches
		}
        }
}


void sorting()
{	int xo=0;
	q = list;		//first location
	r = q->next;		//second location
	if(list == NULL)		//to check whether it is empty or not
	{
		printf("\n Linked List is empty.\n");
	}
	else{
		while(q!=NULL)		//running a while till it reaches its very last element
		{
			r = q->next;	//r to point out next of q
			while(r!=NULL)	//running till r the end of the linked list
			{
				if(q->data>r->data)		//checking whether q's data is smaller or not
				{
					xo = q->data;		//xo storing into temporary variable for swappp
					q->data = r->data;	//swapping the data of q and r for swappp
					r->data = xo;		//back to r for swappp
				}
				r = r->next;			//r to point out it's next*
			}
			q = q->next;				//q to point out it's next*
		}
	}
}

void display()
{
	if(list==NULL)
        {
                printf("\n Linked List is empty.\n");
        }
        else
        {
		printf(" Elements :-");
		q=list;
		counter = 0;
		while(q != NULL)
		{	
			printf("%d\t",q->data);
			q = q->next;
			counter++; // to count total number of elements in the linked list
		}
		printf(" Total count of elements = %d",counter);
	}
}

void counting()
{
	if(list==NULL)
        {
                printf("\n Linked List is empty.\n");
        }
        else
        {
                q=list;
                counter = 0;
                while(q != NULL)
                {
                        q = q->next;
                        counter++; // to count total number of elements in the linked list
                }
                printf("\n Total count of elements = %d\n",counter);
        }
}

void search()
{
	int data1;
        if(list == NULL)
        {
                printf("\n Linked List is empty.\n");    //if it's empty.
        }
        else
        {
                printf("\n Enter element to search.\n");
                scanf("%d",&data1);                                             // to search the particular node.
                q = list;
                while(q->data != data1 && q!=NULL)
                {
			if(q->next == NULL)
			{
				break;
			}
                        q = q->next;
                }
		if(q->data == data1)
		{
			printf("\n Element found.\n");
		}
		else
		{
			printf("\n Element not found\n");
		}
	}
}

void reverse()
{
	if(list == NULL)
	{
		printf("\n Linked list is empty. \n");
	}
	else
	{
		q = s = list;			// q and s setting these to list which is very first element of the linked list.
		temp = NULL;			// setting temp pointer to NULL.
		r = q->next;			// r to second element
		while(r!=NULL)			// loop till r isn't NULL
		{
			temp = q;		// storing q first element pointer to temp
			q = r;			// q to store next location 
			r = q->next;		// while we set r to q's next element pointer which is 3rd element
			q->next = temp;		// setting q to very first element back again.
		}
		list = q;			// very important to set list to very first location because its now reversed to list to should point to very first element of linked list
		s->next = NULL;			// s->next is NULL because very last element linked list should be NULL that's why we are storing NULL into s->next 'cause s is already pointing at last element since it's reversed.
	}
}



