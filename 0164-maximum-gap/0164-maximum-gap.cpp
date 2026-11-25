class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 0;

        int size = max(1, (mx - mn) / (n - 1));
        int count = (mx - mn) / size + 1;

        vector<int> bucketMin(count, INT_MAX);
        vector<int> bucketMax(count, INT_MIN);

        for (int x : nums) {
            int i = (x - mn) / size;
            bucketMin[i] = min(bucketMin[i], x);
            bucketMax[i] = max(bucketMax[i], x);
        }

        int ans = 0;
        int prev = mn;

        for (int i = 0; i < count; i++) {
            if (bucketMin[i] == INT_MAX)
                continue;

            ans = max(ans, bucketMin[i] - prev);
            prev = bucketMax[i];
        }

        return ans;
    }
};