#include "visualiser.hpp"
#include "../graph/graph.hpp"
#include <cmath>

Visualiser::Visualiser() {}

void Visualiser::drawCube(sf::RenderWindow& window, const Graph& graph, float angleX, float angleY) {
    auto nodes = graph.getNodePositions();
    auto edges = graph.getEdges();

    rotate(nodes, angleX, angleY);

    for (const auto& edge : edges) {
        auto start = projectTo2D(nodes[edge.first]);
        auto end = projectTo2D(nodes[edge.second]);

        sf::Vertex line[] = {
            sf::Vertex(start),
            sf::Vertex(end)
        };
        window.draw(line, 2, sf::Lines);
    }
}

void Visualiser::rotate(std::vector<sf::Vector3f>& nodes, float angleX, float angleY) {
    for (auto& node : nodes) {
        float x = node.x;
        float y = node.y;

        // X twisting
        node.y = y * cos(angleX) - node.z * sin(angleX);
        node.z = node.z * cos(angleX) + y * sin(angleX);

        // Y twisting
        node.x = x * cos(angleY) + node.z * sin(angleY);
        node.z = node.z * cos(angleY) - x * sin(angleY);
    }
}

sf::Vector2f Visualiser::projectTo2D(const sf::Vector3f& point) {
    float scale = 200.0f / (200.0f + point.z);
    return sf::Vector2f(point.x * scale + 250, point.y * scale + 250);
}
