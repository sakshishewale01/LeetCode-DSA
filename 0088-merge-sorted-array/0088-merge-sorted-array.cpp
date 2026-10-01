class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // STEP 1: Start pointers from the END
        int i = m - 1;       // Last real element of nums1
        int j = n - 1;       // Last element of nums2
        int k = m + n - 1;   // Last position of nums1


        // STEP 2: Compare elements from the back
        // and put the larger element at the back
        while(i >= 0 && j >= 0) {

            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }


        // STEP 3: If nums2 still has elements,
        // copy them into nums1
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }

        // No need to copy remaining nums1 elements.
        // They are already in their correct positions.
    }
};