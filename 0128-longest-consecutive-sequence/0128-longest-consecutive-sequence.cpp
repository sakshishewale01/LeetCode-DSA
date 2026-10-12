//For O(n) time complexity
class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        // STEP 1: Store all numbers in a set
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        // STEP 2: Store the longest sequence length
        int longest = 0;

        // STEP 3: Check each unique number
        for(auto x : s) {

            // STEP 4: Start counting only if x is the beginning
            if(s.find(x - 1) == s.end()) {

                int current = x;
                int count = 1;

                // STEP 5: Check consecutive numbers
                while(s.find(current + 1) != s.end()) {
                    current++;
                    count++;
                }

                // STEP 6: Update the longest length
                longest = max(longest, count);
            }
        }

        // STEP 7: Return the answer
        return longest;
    }
};

/*
//another easy way to solve but O(nlogn) time complexity

class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        
        if(nums.size()==0) return 0;

        sort(nums.begin(),nums.end());

        int count = 1;
        int longest = 1;

        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            continue;

            if(nums[i] == nums[i - 1] + 1)
            count++;

            else
            {
                count = 1;
            }

            longest = max(longest,count);
        }

        return longest;
    }
    */