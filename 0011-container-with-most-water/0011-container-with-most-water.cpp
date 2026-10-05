class Solution {
public:

    int maxArea(vector<int>& height) {

        // STEP 1: Put one pointer at each end
        int left = 0;
        int right = height.size() - 1;

        // STEP 2: Store maximum water
        int maxWater = 0;

        // STEP 3: Move pointers towards each other
        while(left < right) {

            // STEP 4: Width between the two lines
            int width = right - left;

            // STEP 5: Water depends on the shorter line
            int h = min(height[left], height[right]);

            // STEP 6: Calculate current water
            int area = width * h;

            // STEP 7: Update maximum
            maxWater = max(maxWater, area);

            // STEP 8: Move the shorter line
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxWater;
    }
};