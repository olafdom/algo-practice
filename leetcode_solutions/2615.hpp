#pragma once

#include <vector>
#include <unordered_map>
#include <utility>
#include <cmath>

class Solution {
public:
    std::vector<long long> distance(std::vector<int>& nums) {
        int n = nums.size();

        std::unordered_map<int, std::pair<long long, long long>> prefix;
        std::unordered_map<int, std::pair<long long, long long>> suffix;
        
        std::vector<long long> ans1(n, 0);
        std::vector<long long> ans2(n, 0);
        
        for(int i = 0; i < n; ++i) {
            int val = nums[i];
            if(prefix.find(val) != prefix.end()) {
                long long k = prefix[val].first;
                long long sum_p = prefix[val].second;
                ans1[i] = k * i - sum_p;
            }
            prefix[val].first++;
            prefix[val].second += i;
        }

        for(int i = n - 1; i >= 0; --i) {
            int val = nums[i];
            if(suffix.find(val) != suffix.end()) {
                long long k = suffix[val].first;
                long long sum_p = suffix[val].second;
                ans2[i] = sum_p - k * i;
            }
            suffix[val].first++;
            suffix[val].second += i;
        }

        std::vector<long long> ans(n, 0);
        for(int i = 0; i < n; ++i) {
            ans[i] = ans1[i] + ans2[i];   
        }
        
        return ans;
    }
};