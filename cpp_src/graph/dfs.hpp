#pragma once
#include "graph.hpp"
#include <iostream>
#include <stdexcept>

inline void dfsHelper(const Graph& graph, int currentNode, std::vector<bool>& visited) {
    std::cout << "Node: " << currentNode << std::endl;
    for(auto node : graph.getNeighbours(currentNode)) {
        if(!visited[node]) {
            visited[node] = true;
            dfsHelper(graph, node, visited);
        }
    }
}

inline void runDfs(const Graph& graph, int initialNode) {
    if(initialNode < 0 || initialNode >= graph.getNodeCount()) throw std::invalid_argument("Node index is out of bounds!");
    std::vector<bool> visited(graph.getNodeCount(), false);
    visited[initialNode] = true;
    std::cout << "Starting Depth-First-Search:" << std::endl;
    dfsHelper(graph, initialNode, visited);
    std::cout << "Finished Depth-First-Search" << std::endl;
}