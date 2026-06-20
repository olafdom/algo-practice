#pragma once

#include <vector>
#include <unordered_map>
#include <cmath>

template <typename T>
    int countMinReplacements(const std::vector<T>& v1, const std::vector<T>& v2, const std::vector<int>& pos) {
        std::unordered_map<T, int> count;
        
        for (int i : pos) {
            count[v1[i]]++;
            count[v2[i]]--;
        }
        
        int replacements = 0;
        for (const auto& pair : count) {
            replacements += std::abs(pair.second);
        }
        
        return replacements / 2;
    }