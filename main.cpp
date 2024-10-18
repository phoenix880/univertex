#include <SFML/Graphics.hpp>
#include "visualisation/visualiser.hpp"
#include "utils/memory_manager.hpp"
#include "graph/graph.hpp"
#include "graph/algorithms.hpp"

int main() {
    MemoryManager memoryManager; // Initialisation of memory manager
    sf::RenderWindow window(sf::VideoMode(500, 500), "Rotating Cube");

    Graph& graph = Graph::getInstance();
    graph.createCube(65.0f); // Size of the cube

    Visualiser* visualiser = memoryManager.allocate<Visualiser>();

    float angleX = 90.0f;
    float angleY = 0.0f;
    const float rotationSpeed = 0.4f;

    sf::Clock clock;

    std::cout << "Performing BFS:" << std::endl;
    Algorithms::breadthFirstSearch(graph.getNodes()[0]);

    std::cout << "\nPerforming DFS:" << std::endl;
    Algorithms::depthFirstSearch(graph.getNodes()[0]);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) if (event.type == sf::Event::Closed) window.close();

        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        // Update rotation angles
        angleX += rotationSpeed * deltaTime;
        angleY += rotationSpeed * deltaTime;

        window.clear(sf::Color::Black);
        visualiser->drawCube(window, graph, angleX, angleY);
        window.display();
    }

    memoryManager.deallocate(visualiser); // Deallocation of an object

    return 0;
}
