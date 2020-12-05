#pragma once
#include <vector>
#include <cassert>
#include <iostream>
#include <queue>//bfs

class Graph {
private:
	std::vector<std::vector<int>> adj_matrix;
public:

	Graph() = default;
	Graph(size_t num_verticies);

	void addEdge(int v, int u);

	void bfs(int start);

	void dfs(int v, std::vector<bool>& visited);
	void dfs(int v) {
		std::vector<bool> visited(this->adj_matrix.size());
		dfs(v, visited);
	}

	void printAdjMatrix();
};