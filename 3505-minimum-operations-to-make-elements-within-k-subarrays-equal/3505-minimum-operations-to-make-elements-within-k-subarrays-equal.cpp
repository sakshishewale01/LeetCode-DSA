
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> s1, s2;
        long long sum1 = 0, sum2 = 0;

        // s1 contains smaller half, s2 contains larger half
        auto balance = [&]() {
            while (s1.size() > s2.size() + 1) {
                int val = *s1.rbegin();
                s1.erase(s1.find(val));
                sum1 -= val;

                s2.insert(val);
                sum2 += val;
            }

            while (s1.size() < s2.size()) {
                int val = *s2.begin();
                s2.erase(s2.find(val));
                sum2 -= val;

                s1.insert(val);
                sum1 += val;
            }
        };

        auto add = [&](int val) {
            if (s1.empty() || val <= *s1.rbegin()) {
                s1.insert(val);
                sum1 += val;
            } else {
                s2.insert(val);
                sum2 += val;
            }

            balance();
        };

        auto remove = [&](int val) {
            if (val <= *s1.rbegin()) {
                s1.erase(s1.find(val));
                sum1 -= val;
            } else {
                s2.erase(s2.find(val));
                sum2 -= val;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            int median = *s1.rbegin();

            return 1LL * median * s1.size() - sum1
                 + sum2 - 1LL * median * s2.size();
        };

        // Step 1: Calculate cost of every window of size x
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        for (int i = 0; i <= n - x; i++) {
            cost[i] = getCost();

            if (i < n - x) {
                remove(nums[i]);
                add(nums[i + x]);
            }
        }

        // Step 2: DP to choose k non-overlapping windows
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                // Skip current element
                dp[j][i] = dp[j][i - 1];

                // Select a window of size x
                if (i >= x) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
