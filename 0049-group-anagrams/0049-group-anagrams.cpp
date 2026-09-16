#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());

            groups[key].push_back(word);
        }

        vector<vector<string>> answer;

        for (auto& entry : groups) {
            answer.push_back(entry.second);
        }

        return answer;
    }
};