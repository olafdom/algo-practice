#pragma once
#include <vector>
#include <stdexcept>

class Graph {
private:
    int nodeCount;
    int edgeCount;
    std::vector<std::vector<int>> graph;

public:
    Graph(int initialNodeCount) : edgeCount(0) {
        if (nodeCount < 0) throw std::invalid_argument("Node count cannot be negative!");
        graph.resize(nodeCount);
    }

    void addEdge(int a, int b) {
        if (a < 0 || a >= nodeCount || b < 0 || b >= nodeCount) throw std::out_of_range("Node index is out of bounds!");
        edgeCount++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    const std::vector<int>& getNeighbours(int node) const { 
        if (node < 0 || node >= nodeCount) throw std::out_of_range("Cannot get neighbours: node index is out of bounds!");
        return graph[node]; 
    }

    const int getNodeCount() const { return nodeCount; }
    const int getEdgeCount() const { return edgeCount; }
};