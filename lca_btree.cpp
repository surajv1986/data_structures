/* A program to implement binary tree */
#include<stdio.h>
#include<stdlib.h>


class Binary_tree {
	public:
	   struct node {
  	    int data;
 	    struct node *left;
 	    struct node *right;
	   };	
	struct node *root = NULL;
	
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

};

int main(void)
{
 	Binary_tree btree;

	btree.root = btree.insert(btree.root, 50);
	btree.insert(btree.root, 30);
	btree.insert(btree.root, 20);
	btree.insert(btree.root, 40);
	btree.insert(btree.root, 70);
	btree.insert(btree.root, 60);
	btree.insert(btree.root, 80);
	printf("Begining Preorder Traversal of binary tree\n");
	btree.preorder(btree.root);
	printf("Begining Inorder Traversal of binary tree\n");
	btree.inorder(btree.root);
	printf("Begining Post Order Traversal of binary tree\n");
	btree.postorder(btree.root);

	return 0;
}
