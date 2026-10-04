class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        // STEP 1: Put all numbers into a set
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }


        // STEP 2: Store the longest sequence
        int longest = 0;


        // STEP 3: Traverse each UNIQUE number
        for(auto x : s) {

            // STEP 4: Check if x is the START
            // of a consecutive sequence
            if(s.find(x - 1) == s.end()) {

                int current = x;
                int count = 1;


                // STEP 5: Keep checking next numbers
                while(s.find(current + 1) != s.end()) {

                    current++;
                    count++;
                }


                // STEP 6: Update longest sequence
                longest = max(longest, count);
            }
        }


        // STEP 7: Return answer
        return longest;
    }
};