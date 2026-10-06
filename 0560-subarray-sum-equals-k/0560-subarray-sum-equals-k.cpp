class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {

        // STEP 1: Store prefix sum frequencies
        unordered_map<int, int> mp;

        // STEP 2: Prefix sum
        int sum = 0;

        // STEP 3: Answer
        int count = 0;

        // STEP 4: Empty prefix
        mp[0] = 1;

        // STEP 5: Traverse array
        for(int i = 0; i < nums.size(); i++) {

            // Add current element
            sum += nums[i];

            // STEP 6: Check required previous sum
            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // STEP 7: Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};