class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {

        // STEP 1: Create n x n matrix
        vector<vector<int>> matrix(n, vector<int>(n));

        // STEP 2: Four boundaries
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        // STEP 3: Number to insert
        int num = 1;

        // STEP 4: Fill the matrix in spiral order
        while(top <= bottom && left <= right) {

            // STEP 5: Fill TOP row → left to right
            for(int i = left; i <= right; i++) {
                matrix[top][i] = num;
                num++;
            }
            top++;

            // STEP 6: Fill RIGHT column → top to bottom
            for(int i = top; i <= bottom; i++) {
                matrix[i][right] = num;
                num++;
            }
            right--;

            // STEP 7: Fill BOTTOM row → right to left
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    matrix[bottom][i] = num;
                    num++;
                }
                bottom--;
            }

            // STEP 8: Fill LEFT column → bottom to top
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
        }

        return matrix;
    }
};