class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int,int> count;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;

            if(count[nums[i]] > n/2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};