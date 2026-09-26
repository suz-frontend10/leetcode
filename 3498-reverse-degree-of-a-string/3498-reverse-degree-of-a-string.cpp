class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int revPos = 26 - (s[i] - 'a');  // a->26, b->25, ..., z->1
            ans += revPos * (i + 1);         // 1-based index
        }

        return ans;
    }
};