#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>
#include <SFML/System/Vector3.hpp>

struct Node {int id;};

class Graph {
private:
    std::vector<Node> nodes;
    std::unordered_map<int, std::vector<int>> adjacencyList;
    std::vector<sf::Vector3f> nodePositions;
    std::vector<std::pair<int, int>> edges;

    Graph() {}

public:
    static Graph& getInstance();
    void addNode(const Node& node);
    void addEdge(int fromNodeId, int toNodeId);
    const std::vector<Node>& getNodes() const;
    const std::vector<Node>& getNeighbors(const Node& node) const;
    void createCube(float size);
    const std::vector<sf::Vector3f>& getNodePositions() const;
    const std::vector<std::pair<int, int>>& getEdges() const;

    // Disable copying and assignment
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
};

#endif // GRAPH_HPP
