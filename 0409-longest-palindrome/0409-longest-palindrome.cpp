class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto &p : freq) {
            if (p.second % 2 == 0) {
                length += p.second;
            } else {
                length += p.second - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            length++;
        }

        return length;
    }
};