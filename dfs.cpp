/* A program to demonstrate Depth First Search */
#include<iostream>
#include<bits/stdc++.h>
#include<stdbool.h>

using namespace std;

int adj[9][9] = {{1, 1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 0}, 
	         {0, 0, 1, 0, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 0 , 1, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 0, 1, 0, 1, 1, 0},
                 {1, 0, 1, 0, 0, 0, 1, 0, 1}};

enum vertices{A, B, C, D, E, F, G, H, S};
bool visited[9];
stack <int> dfs_stack;
char op_sequence[9];

int add_to_output(int v)
{
	static int i = 0;

	switch(v) {
	case 0:
		op_sequence[i] = 'A';
		break;
	case 1:	
		op_sequence[i] = 'B';
		break;
	
	case 2:	
		op_sequence[i] = 'C';
		break;
	case 3:	
		op_sequence[i] = 'D';
		break;
	case 4:	
		op_sequence[i] = 'E';
		break;
	case 5:	
		op_sequence[i] = 'F';
		break;
	case 6:	
		op_sequence[i] = 'G';
		break;
	case 7:	
		op_sequence[i] = 'H';
		break;
	case 8:	
		op_sequence[i] = 'S';
		break;
	default:
		cout << "Invalid vertice index" <<endl;
	}
	i++;

	return 0;
}

inline void mark_visited(int vertice)
{
	visited[vertice] = true;	
}

int find_adjacent_vertices(int v)
{
	int i = 0;
	int const_i = v;
	
	for (i = 0; i < 9; i++) {
		if((adj[v][i] == 1) && (i != v)) {
			if(visited[i] == false) {				
				return i;		
			}	
		}
	}

	return -1;
}

int print_output(int V)
{
	int i = 0;

	for (i = 0; i < V; i++) 
		cout << op_sequence[i] << '\t';
	cout << endl;	
	
	return 0;
}

int main(void)
{
	/* Define the number of vertices */
	int V = 9;

	int working_element = 0;
	
	/* Add the first working element to the tos and include it in the output sequence and mark it visited */
	dfs_stack.push(working_element);
	add_to_output(working_element);
	mark_visited(working_element);
	while (1) {
		/* check un visited adjacent vertices */
		working_element = find_adjacent_vertices(working_element);
		/* if there are no un visited vertices */
		if (working_element == -1) {
			if(dfs_stack.empty())
				break;
			working_element = dfs_stack.top();
			dfs_stack.pop();
		} else {
			dfs_stack.push(working_element);
			add_to_output(working_element);
			mark_visited(working_element);
		}
	}
	print_output(V);

	return 0;
}
