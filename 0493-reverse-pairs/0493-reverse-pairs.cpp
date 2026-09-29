class Solution {
public:

    //  Merge two sorted halves
    // Also count reverse pairs between them
    long long merge(vector<int>& nums, int low, int mid, int high) {

        long long count = 0;

        // --------------------------------
        //  Count Reverse Pairs
        // --------------------------------

        int j = mid + 1;

        for(int i = low; i <= mid; i++) {

            // Find elements in right half such that:
            // nums[i] > 2 * nums[j]

            while(j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            // All elements before j form reverse pairs
            count += j - (mid + 1);
        }


        // --------------------------------
        //  Normal Merge
        // --------------------------------

        vector<int> temp;

        int i = low;
        j = mid + 1;

        // Compare elements of both sorted halves
        while(i <= mid && j <= high) {

            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // Copy remaining elements from left half
        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        // Copy remaining elements from right half
        while(j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        // Put sorted elements back into nums
        for(int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }

        return count;
    }


    //  Divide the array
    long long mergeSort(vector<int>& nums, int low, int high) {

        // Only one element
        // means no reverse pair
        if(low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long count = 0;

        // Count reverse pairs in left half
        count += mergeSort(nums, low, mid);

        // Count reverse pairs in right half
        count += mergeSort(nums, mid + 1, high);

        // Count reverse pairs between
        // left half and right half
        count += merge(nums, low, mid, high);

        return count;
    }


    // Start the process
    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};