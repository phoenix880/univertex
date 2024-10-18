#include "graph.hpp"
#include <algorithm>
#include <SFML/System/Vector3.hpp>

Graph& Graph::getInstance() {
    static Graph instance;
    return instance;
}

void Graph::addNode(const Node& node) {
    nodes.push_back(node);
    adjacencyList[node.id] = std::vector<int>();
}

void Graph::addEdge(int fromNodeId, int toNodeId) {adjacencyList[fromNodeId].push_back(toNodeId);}

const std::vector<Node>& Graph::getNodes() const {return nodes;}

const std::vector<Node>& Graph::getNeighbors(const Node& node) const {
    static std::vector<Node> neighbors;
    neighbors.clear();
    for (int neighborId : adjacencyList.at(node.id)) {
        auto it = std::find_if(nodes.begin(), nodes.end(),
                               [neighborId](const Node& n) { return n.id == neighborId; });
        if (it != nodes.end()) neighbors.push_back(*it);
    }
    return neighbors;
}

void Graph::createCube(float size) {
    nodes.clear();
    adjacencyList.clear();
    nodePositions = {{-size, -size, -size}, {-size, -size, size}, {-size, size, -size}, {-size, size, size},
    				{size, -size, -size}, {size, -size, size}, {size, size, -size}, {size, size, size}};

    for (int i = 0; i < 8; ++i) addNode(Node{i});

    edges = {{0, 1}, {1, 3}, {3, 2}, {2, 0},
    		{4, 5}, {5, 7}, {7, 6}, {6, 4},
			{0, 4}, {1, 5}, {2, 6}, {3, 7}};

    for (const auto& edge : edges) addEdge(edge.first, edge.second);
}

const std::vector<sf::Vector3f>& Graph::getNodePositions() const {return nodePositions;}
const std::vector<std::pair<int, int>>& Graph::getEdges() const {return edges;}
