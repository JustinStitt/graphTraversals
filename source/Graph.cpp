#include "Graph.hpp"

Graph::Graph(size_t num_verticies) {
	this->adj_matrix.resize(num_verticies);
	for (auto& r : this->adj_matrix)
		r.resize(num_verticies);
	//NxN adjacency matrix
}

void Graph::addEdge(int v, int u) {

	assert((v < this->adj_matrix.size()) && 
		   (u < this->adj_matrix.size()), 
		   "Vertex doesn't exist");

	this->adj_matrix[v][u] = 1;
	this->adj_matrix[u][v] = 1;
}

void Graph::bfs(int start) {
	//breadth first search utilizes a queue
	std::queue<int> q;
	std::vector<bool> visited(this->adj_matrix.size());/*keeps track of whether or 
	not a node has been visited before*/
	q.push(start);//add our start to our queue
	visited[start] = 1;//it's a given that we have visited the starting vertexc

	while (!q.empty()) {//while our queue is not empty
		//print current node
		std::cout << " " << q.front();
		//add all adjacent verticies to queue
		for (int u{}; u < this->adj_matrix[q.front()].size(); ++u) {
			if (this->adj_matrix[q.front()][u] and
				!visited[u]) {
				q.push(u);
				visited[u] = 1;//we have visited this node
			}
		}
		//remove from front queue
		q.pop();
	}
}


void Graph::dfs(int v, std::vector<bool>& visited) {
	//dfs utilizes recursion
	std::cout << " " << v;
	visited[v] = 1;//visited vertex v
	//for every adjacent vertex, call dfs again -- recursively.
	for (int u{}; u < this->adj_matrix[v].size(); ++u) {
		if (this->adj_matrix[v][u] and
			!visited[u]) {
			dfs(u, visited);
		}
	}

}


void Graph::printAdjMatrix() {
	for (auto& r : this->adj_matrix) {
		for (auto& e : r) {
			std::cout << " " << e;
		} std::cout << "\n";
	}
}
