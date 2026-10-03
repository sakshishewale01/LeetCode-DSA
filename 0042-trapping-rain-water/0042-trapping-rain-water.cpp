class Solution {
public:

    int trap(vector<int>& height) {

        // STEP 1: Two pointers
        int left = 0;
        int right = height.size() - 1;


        // STEP 2: Store the highest wall
        // seen from left and right
        int leftMax = 0;
        int rightMax = 0;


        // STEP 3: Store total trapped water
        int water = 0;


        // STEP 4: Process until pointers meet
        while(left <= right) {

            // --------------------------------
            // If left wall is smaller
            // --------------------------------
            if(height[left] <= height[right]) {

                // Update left maximum
                if(height[left] >= leftMax) {
                    leftMax = height[left];
                }

                // Otherwise water can be trapped
                else {
                    water += leftMax - height[left];
                }

                // Move left pointer
                left++;
            }


            // --------------------------------
            // If right wall is smaller
            // --------------------------------
            else {

                // Update right maximum
                if(height[right] >= rightMax) {
                    rightMax = height[right];
                }

                // Otherwise water can be trapped
                else {
                    water += rightMax - height[right];
                }

                // Move right pointer
                right--;
            }
        }


        // STEP 5: Return total water
        return water;
    }
};