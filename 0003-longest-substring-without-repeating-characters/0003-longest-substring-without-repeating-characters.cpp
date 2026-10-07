class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        // STEP 1: Store the last position of each character
        unordered_map<char, int> mp;

        // STEP 2: Left side of our window
        int left = 0;

        // STEP 3: Store maximum length
        int maxLength = 0;

        // STEP 4: Move right pointer through the string
        for(int right = 0; right < s.size(); right++) {

            // STEP 5: If character was seen before
            if(mp.find(s[right]) != mp.end()) {

                // Move left after the previous occurrence
                left = max(left, mp[s[right]] + 1);
            }

            // STEP 6: Store latest position
            mp[s[right]] = right;

            // STEP 7: Calculate current window length
            int length = right - left + 1;

            // STEP 8: Update maximum
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};