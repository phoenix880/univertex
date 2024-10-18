#ifndef VISUALISER_HPP
#define VISUALISER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Graph; // Forward declaration

class Visualiser {
public:
    Visualiser();
    void drawCube(sf::RenderWindow& window, const Graph& graph, float angleX, float angleY);

private:
    void rotate(std::vector<sf::Vector3f>& nodes, float angleX, float angleY);
    sf::Vector2f projectTo2D(const sf::Vector3f& point);
};

#endif // VISUALISER_HPP
