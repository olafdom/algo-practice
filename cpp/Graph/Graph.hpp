#pragma once
#include <vector>

class Graph {
private:
    int nodeCount;
    int edgeCount;
    std::vector<std::vector<int>> graph;

public:
    Graph(int initialNodeCount) : edgeCount(0) {
        if (nodeCount < 0) return;
        graph.resize(nodeCount);
    }

    void addEdge(int a, int b) {
        edgeCount++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    const std::vector<int>& getNeighbours(int node) const { 
        return graph[node]; 
    }

    int getNodeCount() const { return nodeCount; }
    int getEdgeCount() const { return edgeCount; }
};