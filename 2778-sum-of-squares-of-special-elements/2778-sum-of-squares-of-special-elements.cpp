
class Solution {
public:

    int sumOfSquares(vector<int>& nums) {

        // STEP 1: Get the size of the array
        int n = nums.size();

        // STEP 2: Store the sum
        int sum = 0;

        // STEP 3: Traverse the array using 1-based positions
        for(int i = 1; i <= n; i++) {

            // STEP 4: Check if i divides n
            if(n % i == 0) {

                // STEP 5: Add the square of nums[i-1]
                sum += nums[i - 1] * nums[i - 1];
            }
        }

        // STEP 6: Return the total
        return sum;
    }
};
