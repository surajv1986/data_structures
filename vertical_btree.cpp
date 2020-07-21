/* A C++ Program to print vertical order of binary tree */
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

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

void findVerticalOrder(struct node *root, int hd, map <int, vector <int>> &m)
{
	if (root == NULL) 
		return;
	/* Preorder traversal */
	m[hd].push_back(root->data);
	findVerticalOrder(root->left, hd - 1, m);
	findVerticalOrder(root->right, hd + 1, m);

}


void print_vertical_order(struct node *root)
{
	map <int, vector <int>> m;
	int hd = 0;
	
	findVerticalOrder(root, hd, m);
	map <int, vector<int>>::iterator i;
	for (i = m.begin(); i != m.end(); i++) {
		cout << i->second[i] << endl;	
	}

}

int main(void)
{
    struct node *root = new_node(1); 
    root->left = new_node(2); 
    root->right = new_node(3); 
    root->left->left = new_node(4); 
    root->left->right = new_node(5); 
    root->right->left = new_node(6); 
    root->right->right = new_node(7); 
    root->right->left->right = new_node(8); 
    root->right->right->right = new_node(9); 
    cout << "Vertical order traversal is n"; 
    print_vertical_order(root); 
    return 0; 
}
