/* A program to convert a binary tree to bst */
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};


int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

struct node *new_node(int data)
{
	struct node *node = (struct node *) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

int count_nodes(struct node *root)
{
	if (root == NULL) 
		return 0;

	return (count_nodes(root->left) + count_nodes(root->right) + 1);
}

void storeInorder(struct node *root, int storage_array[], int *i)
{
	if(root == NULL)
		return;

	storeInorder(root->left, storage_array, i);
	storage_array[*i] = root->data;
	(*i)++;
	storeInorder(root->right, storage_array, i);

}

void array_to_bst(struct node *root, int *storage_array, int *index)
{
	if (root == NULL)
		return;
	array_to_bst(root->left, storage_array, index);
	root->data = storage_array[*index];
	(*index)++;
	array_to_bst(root->right, storage_array, index);
}


void btree_to_bst(struct node *root)
{
	int n;
	int i = 0;
	if (root == NULL)
		return;

	n = count_nodes(root);
	int *temp_array = new int[n];
	storeInorder(root, temp_array, &i);
	qsort(temp_array, n, sizeof(temp_array[0]), compare);
	i = 0;
	array_to_bst(root, temp_array, &i);
	delete[] temp_array;

}

void print_InOrder(struct node *root)
{
	if (root == NULL)
		return;
	print_InOrder(root->left);
	printf("%d\n", root->data);
	print_InOrder(root->right);
}

int main(void)
{

	struct node *root = NULL;
	
	root = new_node(10);
	root->left = new_node(30);
	root->right = new_node(15);
	root->left->left = new_node(20);
	root->right->right = new_node(5);
	print_InOrder(root);
        btree_to_bst(root);
	printf("After conversion to bst \n");	
	print_InOrder(root);

	return 0;
}
