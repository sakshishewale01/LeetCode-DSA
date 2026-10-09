
class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {

        // STEP 1: Sort the array
        sort(nums.begin(), nums.end());

        // STEP 2: Start with the first three numbers
        int closestSum = nums[0] + nums[1] + nums[2];

        // STEP 3: Fix the first number
        for(int i = 0; i < nums.size() - 2; i++) {

            // STEP 4: Two pointers
            int j = i + 1;
            int k = nums.size() - 1;

            // STEP 5: Find the closest sum
            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                // STEP 6: Update if this sum is closer
                if(abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                // STEP 7: Exact match found
                if(sum == target) {
                    return sum;
                }

                // STEP 8: Move the correct pointer
                else if(sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        // STEP 9: Return the closest sum
        return closestSum;
    }
};