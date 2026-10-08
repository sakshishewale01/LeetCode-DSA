class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        // STEP 1: Start with the first string as prefix
        string prefix = strs[0];

        // STEP 2: Compare prefix with every other string
        for(int i = 1; i < strs.size(); i++) {

            // STEP 3: Find how many characters match
            int j = 0;

            while(j < prefix.size() &&
                  j < strs[i].size() &&
                  prefix[j] == strs[i][j]) {
                j++;
            }

            // STEP 4: Keep only the matching part
            prefix = prefix.substr(0, j);

            // STEP 5: If nothing matches, return ""
            if(prefix == "") {
                return "";
            }
        }

        // STEP 6: Return common prefix
        return prefix;
    }
};