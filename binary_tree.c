/* A program to implement binary tree */
#include<stdio.h>
#include<stdlib.h>

struct node  
{ 
  int data; 
  struct node *left; 
  struct node *right; 
};

struct node *new_node(int key)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node *));
	temp->data = key;
	temp->right = temp->left = NULL;
}

void preorder(struct node *root)
{
	if (root != NULL) {
		printf("%d\n", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
	
}

void postorder(struct node *root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

struct node *insert(struct node *node, int key)
{
	
	if (node == NULL) 
		return new_node(key);

	if (key < node->data) 
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->left, key);

	return node;
}
int main(void)
{
	struct node *root = NULL;

	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	printf("Begining Preorder Traversal of binary tree\n");
	preorder(root);
	printf("Begining Inorder Traversal of binary tree\n");
	inorder(root);
	printf("Begining Post Order Traversal of binary tree\n");
	postorder(root);
	
	return 0;
}
