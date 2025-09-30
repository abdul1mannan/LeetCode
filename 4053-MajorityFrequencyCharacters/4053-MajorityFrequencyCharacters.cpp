// Last updated: 10/1/2025, 12:46:40 AM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        unordered_map<int, vector<char>> groups;
        for (auto &p : freq) {
            groups[p.second].push_back(p.first);
        }


        int bestSize = 0, bestK = 0;
        vector<char> bestGroup;

        for (auto &g : groups) {
            int k = g.first;
            int size = g.second.size();

            if (size > bestSize || (size == bestSize && k > bestK)) {
                bestSize = size;
                bestK = k;
                bestGroup = g.second;
            }
        }

        return string(bestGroup.begin(), bestGroup.end());
    }
};
