class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long hours = 0;

        for (int p : piles) {
            hours += (p + k - 1) / k; // ceil(p/k)

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canEat(piles, h, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};