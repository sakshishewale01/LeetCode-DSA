class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for (int i = 0; i < s.length(); i++) {
            rows[row] += s[i];

            if (row == 0)
                direction = 1;
            else if (row == numRows - 1)
                direction = -1;

            row += direction;
        }

        string ans = "";

        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }

        return ans;
    }
};