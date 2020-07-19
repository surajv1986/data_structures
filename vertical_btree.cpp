/* A C++ Program to print vertical order of binary tree */
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>


struct node {
	int data;
	struct node *left;
	struct node *right;

};

struct node *new_node(int data)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	if (temp == NULL) {
		cout << "Error Allocating memory" << endl;
		exit(1);
	}
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void findVerticalOrder(node *root, int hd, map <int, vector <int>>)
{
	if (root == NULL) {
	
	
	}


}


void print_vertical_order(Node *root)
{


}

int main(void)
{
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    cout << "Vertical order traversal is n"; 
    printVerticalOrder(root); 
    return 0; 
}
