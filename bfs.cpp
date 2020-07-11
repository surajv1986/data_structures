/* A program to demonstrate Breadth First Search */
#include<iostream>
#include<bits/stdc++.h>
#include<stdbool.h>

using namespace std;

int adj[9][9] = {{1, 1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 0}, 
	         {0, 0, 1, 0, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 0 , 1, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 0, 1, 0, 1, 1, 0},
                 {1, 0, 1, 0, 0, 0, 1, 0, 1}};

enum vertices{A, B, C, D, E, F, G, H, S};
bool visited[9];
queue <int> bfs_queue;
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

int update_working_element(int curr_element)
{
	int new_element = 0;
	static int i = 0;

	if (bfs_queue.empty())
		return -1;

	new_element = bfs_queue.front();
	bfs_queue.pop();

	return new_element;
}
int find_adjacent_vertices(int v)
{
	int i = 0;
	int const_i = v;
	
	for (i = 0; i < 9; i++) {
		if((adj[v][i] == 1) && (i != v)) {
			if(visited[i] == false) {
				bfs_queue.push(i);
				mark_visited(i);
			}	
		}
	}

	return 0;
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
	
	/* Add the first working element to the output sequence */
	add_to_output(working_element);
	mark_visited(working_element);
	while (1) {
		/* Find unvisited adjacent vertices and enqueue them */
		find_adjacent_vertices(working_element);
		/* update working element to first element in queue */
		working_element = update_working_element(working_element);
		/* exit if queue is empty */
		if (working_element == -1)
			break;
		else
			add_to_output(working_element); /* Add updated working element to the output sequence */
	}
	print_output(V);

	return 0;
}
