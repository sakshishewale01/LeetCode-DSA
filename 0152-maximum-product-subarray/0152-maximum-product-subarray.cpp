class Solution {
public:

    int maxProduct(vector<int>& nums) {

        // STEP 1: Start with the first element
        int maxi = nums[0];
        int mini = nums[0];

        // Stores the final maximum product
        int ans = nums[0];


        // STEP 2: Traverse the array
        for(int i = 1; i < nums.size(); i++) {

            int x = nums[i];


           
            // STEP 3: If current number is negative
            // swap maxi and mini
        

            if(x < 0) {
                swap(maxi, mini);
            }


        
            // STEP 4: Decide:
            // Start a new subarray OR
            // Continue the previous subarray
        

            maxi = max(x, maxi * x);

            mini = min(x, mini * x);


         
            // STEP 5: Update final answer
           

            ans = max(ans, maxi);
        }

        return ans;
    }
};