#include "algorithms.hpp"
#include <queue>
#include <stack>
#include <vector>

void Algorithms::breadthFirstSearch(const Node &startNode) {
	const Graph &graph = Graph::getInstance();
	std::queue<Node> q;
	std::unordered_map<int, bool> visited;

	q.push(startNode);
	visited[startNode.id] = true;

	while (!q.empty()) {
		Node current = q.front();
		q.pop();
		std::cout << "Visiting node: " << current.id << std::endl;

		for (const auto &neighbor : graph.getNeighbors(current)) {
			if (!visited[neighbor.id]) {
				q.push(neighbor);
				visited[neighbor.id] = true;
			}
		}
	}
}

void Algorithms::depthFirstSearch(const Node &startNode) {
	const Graph &graph = Graph::getInstance();
	std::stack<Node> s;
	std::unordered_map<int, bool> visited;

	s.push(startNode);

	while (!s.empty()) {
		Node current = s.top();
		s.pop();

		if (!visited[current.id]) {
			std::cout << "Visiting node: " << current.id << std::endl;
			visited[current.id] = true;

			for (const auto &neighbor : graph.getNeighbors(current)) {
				if (!visited[neighbor.id]) s.push(neighbor);
			}
		}
	}
}
