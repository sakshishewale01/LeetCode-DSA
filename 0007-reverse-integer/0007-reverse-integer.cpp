class Solution {
public:

    int reverse(int x) {

        // STEP 1: Store reversed number
        int rev = 0;

        // STEP 2: Keep taking the last digit
        while(x != 0) {

            // STEP 3: Get last digit
            int digit = x % 10;

            // STEP 4: Remove last digit from x
            x = x / 10;

            // STEP 5: Check overflow BEFORE multiplying by 10
            if(rev > INT_MAX / 10 ||
               (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if(rev < INT_MIN / 10 ||
               (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            // STEP 6: Add digit to reversed number
            rev = rev * 10 + digit;
        }

        return rev;
    }
};