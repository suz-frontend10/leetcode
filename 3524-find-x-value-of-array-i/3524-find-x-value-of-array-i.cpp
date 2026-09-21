class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int v = num % k;
            vector<long long> ndp(k, 0);

            // Start new subarray
            ndp[v]++;

            // Extend existing subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int nr = (r * v) % k;
                ndp[nr] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = std::move(ndp);
        }

        return ans;
    }
};