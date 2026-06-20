#pragma once
#include <iostream>
#include <stdexcept>
#include <queue>
#include <vector>
#include "graph.hpp"

inline void runBfs(const Graph& graph, int initialNode) {
    if(initialNode < 0 || initialNode >= graph.getNodeCount()) throw std::invalid_argument("Node index is out of bounds!");
    std::vector<bool> visited(graph.getNodeCount(), false);
    visited[initialNode] = true;
    std::queue<int> q;
    q.push(initialNode);

    std::cout << "Starting Breadth-First-Search:" << std::endl;

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();
        std::cout << "Node: " << currentNode << std::endl;
        for(const auto& node : graph.getNeighbours(currentNode)) {
            if(!visited[node]) {
                visited[node] = true;
                q.push(node);
            }
        }
    }

    std::cout << "Finished Breadth-First-Search" << std::endl;
}