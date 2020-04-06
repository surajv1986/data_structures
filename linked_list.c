/* A simple program to demonstrate singly linked list */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

struct node {
	int data;
	struct node *next;
};

/* Used MERELY to point to the head of the list */
struct node *head = NULL;

int insert_at_beg(int data)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	if(temp == NULL) {
		perror("failed to allocate memory: message from perror\n %s\n");
		exit(1);
	}

	temp->data = data;

	/* check if list is empty */
	if (head == NULL) {
	      head = temp;	  	    
	      head->next = NULL;
	} else {
		/* if list is not empty */
		temp->next = head;
		head = temp;
	}

	return 0;
}

int del_at_beg(void)
{
	struct node *t;	

	/* check if list is empty */
	if (head == NULL) {
		printf("List is Empty cannot delete at beg\n");
		exit(1);      
	} else {
		/* if list is not empty */
		t = head;
		/* increment head */
		t = t->next;
		/* Update head */
		head = t;

	}
}

int insert_at_end(int val)
{
	struct node *t, *temp;
	
	t = head;
	temp = (struct node *) malloc(sizeof(struct node *));
	if(temp == NULL) {
		perror("failed to allocate memory: message from perror\n %s\n");
		exit(1);
	}
	temp->data = val;
	/* check if the list is empty */
	if (t == NULL) {
	
		printf("List empty please insert at begining first\n");

	} else {
		
		while (t->next != NULL) {
			t = t->next;			
		}
		/* Debugging print */
		printf("Element at tail is %d\n", t->data);
		/* point to the new element to be added */
		t->next = temp;
		/* update the last element to point to null */
		temp->next = NULL;
	
	}

}

int del_at_end(void)
{
	struct node *t, *temp;

	t = head;
	if (t == NULL) {
	
		printf("Error: trying to Delete from an empty list\n");
		exit(1);
	}
	/* loop until the second last element is reached */
	while(t->next->next != NULL) {
		t = t->next;
	
	}
	/* Debugging print */
	printf("The data at new tail has to be %d\n", t->data);
	temp = t;
	/* remove the tail element*/
	t->next = NULL;

	return 0;


}
void display_list(void)
{
	struct node *temp;
	
	temp = head;
	/* If list is empty */
	if(temp == NULL)
		printf("Empty List \n");
	else {
		while(temp != NULL) {
			printf("%d->", temp->data);	
			temp = temp->next;
		}
		printf("\n");
	
	}		

}
int main(void)
{
	insert_at_beg(3);
	insert_at_beg(5);
	insert_at_beg(7);
	insert_at_beg(9);
	insert_at_beg(11);
	insert_at_beg(12);
	display_list();
	del_at_beg();
	display_list();
	insert_at_end(15);
	display_list();
	del_at_end();
	display_list();

	return 0;

}

