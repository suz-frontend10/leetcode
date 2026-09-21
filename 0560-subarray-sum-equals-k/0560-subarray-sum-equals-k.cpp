class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int prefix = 0, ans = 0;

        for (int x : nums) {
            prefix += x;
            ans += mp[prefix - k];
            mp[prefix]++;
        }

        return ans;
    }
};