/* A program to implement linked stack */
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

struct node {
	int data;
	struct node *link;
} *top;

int push(int val)
{
	struct node *temp;

	temp = (struct node *) malloc(sizeof(struct node));
	if (temp == NULL) {
		perror("failed to allocate memory: msg from perror %s\n");
		exit(1);
	}
	if (top == NULL) {
		temp->data = val;
		temp->link = NULL;
		top = temp;
	} else {
		temp->data = val;
		temp->link = top;
		top = temp;
	}

	return 0;
}

int pop(void)
{
	struct node *t;

	t = top;
	if (t == NULL) {
		printf("Trying to pop an empty stack\n");
		exit(0);
	}
	printf("Popping element : %d \n", t->data);
	/* increment top to point to the new top of stack */
	top = t->link;
	free(t);

	return 0;
}

int display_stack(void)
{
	struct node *t;

	t = top;
	if (t == NULL) {
		printf("Trying to display an empty stack\n");
		exit(0);
	}
	printf("The elements in the stack are\n");
	while (t != NULL) {
		printf("%d\n", t->data);
		t = t->link;
	}

	return 0;
}


int main(void)
{
	/* A menu for stack primitives demonstration */
	int ret = 0, choice = 0, val = 0, pos = 0;
	char ch;

	printf("Jai Shri Ram:Welcome to my stack demonstration\n");
	while (1) {
		printf("1) Push\n");
		printf("2) Pop\n");
		printf("3) Display Stack Data\n");
		printf("0) quit the program \n ");
		printf("Enter your choice \n");
		scanf("%d", &choice);
		switch (choice) {

		case 0:
			printf("Quitting.....Thanks......\n");
			exit(0);
			break;
		case 1:
			printf("Enter the value to be pushed onto the stack \n");
			scanf("%d", &val);
			ret = push(val);
			break;
		case 2:
			printf("Initiating Pop()\n");
			ret = pop();
			break;
		case 3:
			printf("The payload elements in our stack are: \n");
			ret = display_stack();
			break;
		default:
			printf("Invalid Input:Enter a valid choice number between 0 and 3\n");
		}
	}

	return 0;
}
