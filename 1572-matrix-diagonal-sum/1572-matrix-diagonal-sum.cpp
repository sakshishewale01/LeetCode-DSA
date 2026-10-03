class Solution {
public:

    int diagonalSum(vector<vector<int>>& mat) {

        // STEP 1: Find size of matrix
        int n = mat.size();

        // STEP 2: Store diagonal sum
        int sum = 0;


        // STEP 3: Traverse every row
        for(int i = 0; i < n; i++) {

            // Primary diagonal
            // Position: [i][i]
            sum += mat[i][i];


            // Secondary diagonal
            // Position: [i][n-1-i]
            sum += mat[i][n - 1 - i];
        }


        // STEP 4: If n is odd,
        // the middle element was counted twice
        if(n % 2 == 1) {

            int middle = n / 2;

            sum -= mat[middle][middle];
        }


        // STEP 5: Return answer
        return sum;
    }
};