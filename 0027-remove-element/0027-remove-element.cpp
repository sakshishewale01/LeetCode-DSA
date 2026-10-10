
class Solution {
public:

    int removeElement(vector<int>& nums, int val) {

        // STEP 1: Position to place the next valid element
        int k = 0;

        // STEP 2: Check every element
        for(int i = 0; i < nums.size(); i++) {

            // STEP 3: Keep only elements NOT equal to val
            if(nums[i] != val) {

                // STEP 4: Place valid element at position k
                nums[k] = nums[i];

                // STEP 5: Move to the next position
                k++;
            }
        }

        // STEP 6: Return the number of valid elements
        return k;
    }
};
