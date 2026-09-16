class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            int required = target - nums[i];

            if (seen.find(required) != seen.end())
            {
                return {seen[required], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};