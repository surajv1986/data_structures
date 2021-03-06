/* A simple program to sort a singly linked list */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<stdbool.h>

/* function prototyping section */
int find_list_length(void);

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
	if (temp == NULL) {
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
	if (temp == NULL) {
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
	while (t->next->next != NULL) {
		t = t->next;

	}
	/* Debugging print */
	printf("The data at new tail has to be %d\n", t->data);
	temp = t;
	/* remove the tail element*/
	t->next = NULL;

	return 0;
}

int insert_at_pos(int val, int pos)
{
	struct node *temp, *t;
	int count = 1, ret;

	temp = (struct node *) malloc(sizeof(struct node *));
	if (temp == NULL) {
		perror("Error allocating Memory: msg from perror %s");
		exit(1);
	}
	t = head;
	temp->data = val;
	/* Check for insert at begining of list */
	if (pos == 1) {
		ret = insert_at_beg(val);
	} else {
		while (count != (pos - 1)) {

			if (t == NULL) {
				printf(" List Index out of bounds error:exiting\n");
				exit(1);
			}
			/* increment to point to the subsequent element */
			t = t->next;
			count++;
		}
		/* check for insert at end case*/
		if (t->next == NULL) {
			printf("In case for ins at end\n");
			ret = insert_at_end(val);
		} else {
		/* Debugging print */
		printf("node will be inserted after %d\n", t->data);
		/* link the new node to its successor */
		temp->next = t->next;
		/* link the new node to its predecessor */
		t->next = temp;

		}
	}
	return 0;
}

int del_at_pos(int pos)
{
	struct node *t;
	int count = 1, ret;

	t = head;
	if (t == NULL) {
		printf("Error deleting from empty list\n");
		exit(1);
	} else {
		if (pos == 1) {
			ret = del_at_beg();

		} else {

			while (count != (pos - 1)) {
				t = t->next;
				count++;
				if (t == NULL) {
					printf("ERROR:List Index out of bounds\n");
					exit(1);
				}
			}
			if (t->next == NULL) {
				ret = del_at_end();

			} else {

				/* Debugging print */
				printf("node after %d will be removed\n ", t->data);
				/* link predecessor and successor nodes bypassing the node to be deleted */
				t->next = t->next->next;
			}
		}
	}

}
int traverse_list(int index, bool flag)
{
	struct node *temp;
	int count = 1, length = 0, ret = 0;

	temp = head;
	length = find_list_length();
	if (index > length)
		printf("ERROR: Traverse index %d exceeds list length %d\n", index, length);
	else if (length == 0)
		printf("ERROR: Trying to traverse an empty list\n");
	else {
		while (count <= index) {
			if (flag == true)
				printf("->%d", temp->data);
			if (temp->next == NULL)
				break;
			temp = temp->next;
			count++;
		}
	}
	printf("\n");

	/* return the value at desired index */
	ret = temp->data;
}

int find_list_length(void)
{
	int len = 0;
	struct node *temp = head;

	while (temp != NULL) {
		len++;
		temp = temp->next;
	}

	return len;
}
int bubble_sort_list(void)
{
	int len = 0, i = 0, j = 0, buf;
	struct node *temp = head, *t = head->next;

	len = find_list_length();
	if (len == 0)
		printf("ERROR: Trying to sort empty list\n");
	else {
		for (i = 0; i < len; i++) {
			for (j = 1; j < len; j++) {
				if (temp->data > t->data) {
					buf = temp->data;
					temp->data = t->data;
					t->data = buf;
				}
				if (t->next == NULL)
					break; /* break inner loop */
				t = t->next;
			}
			if (temp->next == NULL)
				break; /* break outer loop */
			temp = temp->next;
		}
	}
}
int main(void)
{
	/* A menu for linked list */
	int ret = 0, choice = 0, val = 0, pos = 0, length = 0;
	char ch;
	while (1) {
		printf("1) Insert at begining\n");
		printf("2) Insert at position\n");
		printf("3) Insert at end\n");
		printf("4) Delete at begining\n");
		printf("5) Delete at position\n");
		printf("6) Delete from end\n");
		printf("7) display the linked list\n");
		printf("8) Sort the list\n");
		printf("0) quit the program \n ");
		printf("Enter your choice \n");
		scanf("%d", &choice);

		switch (choice) {

		case 0:
			printf("Quitting.....Thanks......\n");
			exit(0);
			break;
		case 1:
			printf("Enter the value to be inserted \n");
			scanf("%d", &val);
			ret = insert_at_beg(val);
			break;
		case 2:
			printf("Enter the value and position at which value is to be inserted \n");
			scanf("%d %d", &val, &pos);
			ret = insert_at_pos(val, pos);
			break;
		case 3:
			printf("Enter the value to be inserted \n");
			scanf("%d", &val);
			ret = insert_at_end(val);
			break;
		case 4:
			ret = del_at_beg();
			break;
		case 5:
			printf("Enter the position \n");
			scanf("%d", &pos);
			ret = del_at_pos(pos);
			break;
		case 6:
			printf("Enter the position \n");
			ret = del_at_end();
			break;
		case 7:
			length = find_list_length();
			traverse_list(length, true);
			break;
		case 8:
			bubble_sort_list();
			printf("The sorted list is\n");
			length = find_list_length();
			traverse_list(length, true);
			break;
		default:
			printf("Enter a valid input between 1 and 7 \n");
		}
	}
	return 0;
}

