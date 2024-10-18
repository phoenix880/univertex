#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "graph.hpp"
#include <iostream>

class Algorithms {
public:
	static void breadthFirstSearch(const Node &startNode);
	static void depthFirstSearch(const Node &startNode);
};

#endif // ALGORITHMS_HPP
