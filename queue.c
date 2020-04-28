/* A program to implement linked queue */
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

struct node {
	int data;
	struct node *link;
} *front, *rear;

int create_queue(void)
{
	front = rear = NULL;
	return 0;
}

int enqueue(int val)
{
	struct node *temp;

	temp = (struct node *) malloc(sizeof(struct node *));
	if (temp == NULL) {
		perror("FAILED TO ALLOCATE MEMORY: msg from perror %s\n");
		exit(1);
	}
	temp->data = val;
	printf("The element enqueued is %d \n", temp->data);
	if (front == NULL) {
		front = rear = temp;
		temp->link = NULL;
	} else {
		temp->link = front;
		front = temp;
	}

	return 0;
}

int dequeue(void)
{
	struct node *t, *q;

	t = front;
	q = rear;
	if (t == NULL) {
		printf("ERROR TRYING TO DEQUEUE EMPTY QUEUE\n");
		exit(0);
	}
	if (front == rear) {
		printf("The last element being dequeued is : %d\n", t->data);
		front = rear = NULL;
	} else {
		while (t->link != rear)
			t = t->link;
		printf("The element being dequeued is : %d\n", q->data);
		printf("Data at new rear is : %d\n", t->data);
		/* increment rear*/
		rear = t;
		t->link = NULL;
		free(q);
	}

	return 0;
}
int display_queue(void)
{
	struct node *t;

	t = front;
	if (t == NULL) {
		printf("ERROR trying to display empty queue\n");
		exit(0);
	}
	while (t != NULL) {
		printf("%d\n", t->data);
		t = t->link;
	}

	return 0;
}

int main(void)
{
	/* A menu for queue primitives demonstration */
	int ret = 0, choice = 0, val = 0, pos = 0;
	char ch;

	printf("Jai Shri Ram:Welcome to my queue data structure demonstration\n");
	create_queue();
	while (1) {
		printf("1) Enqueue\n");
		printf("2) Dequeue\n");
		printf("3) Display Queue Data\n");
		printf("0) quit the program \n ");
		printf("Enter your choice \n");
		scanf("%d", &choice);
		switch (choice) {

		case 0:
			printf("Quitting.....Thanks......\n");
			exit(0);
			break;
		case 1:
			printf("Enter the value to be enqueued \n");
			scanf("%d", &val);
			ret = enqueue(val);
			break;
		case 2:
			printf("Initiating dequeue()\n");
			ret = dequeue();
			break;
		case 3:
			printf("The payload elements in our queue are: \n");
			ret = display_queue();
			break;
		default:
			printf("Enter a valid input number between 0 and 3\n");
		}
	}
	return 0;
}
