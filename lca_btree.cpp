/* A program to implement binary tree */
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

vector <int> p1, p2;
bool flag = false;

class Binary_tree {
	public:
	   int n1, n2;
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
			node->right = insert(node->right, key);

		return node;
	}
	void re_init()
	{
		flag = false;
	}
	bool find_path(struct node *root, int n1)
	{	
		if (root == NULL)
			return false;
		/* If the root element is the desired element */
		if (root->data == n1)
			return true;
		if (flag == false)
			p1.push_back(root->data);
		else
			p2.push_back(root->data);
		if (find_path(root->left, n1) || find_path(root->right, n1))
			return true;
		/* required path does not lie on the ltree or rtree of the current node hence pop back this value */
		if (flag == false)
			p1.pop_back();
		else
			p2.pop_back();

		return false;
	}

	void print_path(vector <int> v)
	{
		cout << "The desired path is:";	
		for(auto ir = v.cbegin(); ir != v.cend(); ir++)
			cout << *ir << '\t';
		cout << endl;
	}
	int find_lca(vector <int> v1, vector <int> v2)
	{
		int i = 0, j = 0;

		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		for (i = 0; i < v1.size(); i++) {
			for (j = 0; j < v2.size(); j++) {
				if (v1[i] == v2[j])
					return v1[i];
			}
		}

		return 0;
	}
};


int main(void)
{
 	Binary_tree btree;
	int lca;

	btree.root = btree.insert(btree.root, 50);
	btree.insert(btree.root, 30);
	btree.insert(btree.root, 20);
	btree.insert(btree.root, 40);
	btree.insert(btree.root, 70);
	btree.insert(btree.root, 60);
	btree.insert(btree.root, 80);
	printf("Begining Preorder Traversal of binary tree\n");
	btree.preorder(btree.root);
	cout << "Enter the  nodes to find lca" << endl;
	cin >> btree.n1 >> btree.n2;
	btree.find_path(btree.root, btree.n1);
	flag = true;
	btree.find_path(btree.root, btree.n2);
	lca = btree.find_lca(p1, p2);
	cout << "lca:" << lca << endl;

	return 0;
}
