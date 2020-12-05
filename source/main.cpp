#include <iostream>
#include "Graph.hpp"

int main() {

	Graph g(6);//graph with 6 verticies... 0,1,2,3,4,5
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	std::cout << "\n-------adjacency matrix--------" << std::endl;
	g.printAdjMatrix();
	std::cout << "\n-------bfs--------" << std::endl;
	g.bfs(0);//start node is 0
	std::cout << "\n-------dfs--------" << std::endl;
	g.dfs(0);//start node is 0

	std::cin.get();
	return 0;
}