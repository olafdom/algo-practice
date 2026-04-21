#pragma once
#include <unordered_map>
#include <vector>

class Solution {
public:
    int MAXIMAL_ELEM = -1;
    int calculateDifferences(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& pos) {
    std::unordered_map<int, int> count;
        for(int i : pos) {
            count[v1[i]]++; 
            count[v2[i]]--; 
        }
        int ans = 0;
        for(auto& pair : count) {
            ans += abs(pair.second); 
        }
        return ans / 2;
    }
    void dfs(int v, std::vector<bool>& vis, std::vector<std::vector<int>>& graph, std::vector<int>& component) {
        component.push_back(v);
        vis[v] = true;
        for(int node : graph[v]) {
            if(!vis[node]) dfs(node, vis, graph, component);
        }
    }

    int minimumHammingDistance(std::vector<int>& source, std::vector<int>& target, std::vector<std::vector<int>>& allowedSwaps) {
        std::vector<std::vector<int>> graph(source.size());
        for(const auto& swap : allowedSwaps) {
            int a = swap[0], b = swap[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        std::vector<bool> vis(source.size(), false) ;
        std::vector<std::vector<int>> components;
        for(int i = 0; i < source.size(); ++i) {
            MAXIMAL_ELEM = std::max(MAXIMAL_ELEM, source[i]);
            MAXIMAL_ELEM = std::max(MAXIMAL_ELEM, target[i]);
            if(!vis[i]) {
                std::vector<int> component;
                dfs(i, vis, graph, component);
                components.push_back(component);
            }
        }
        int ans = 0;
        for(std::vector<int>& comp : components) {
            ans += calculateDifferences(source, target, comp);
        }
        return ans;
    }
};