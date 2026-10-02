class Solution {
public:

    int maxProfit(vector<int>& prices) {

        // STEP 1: Store total profit
        int profit = 0;


        // STEP 2: Check every pair of consecutive days
        for(int i = 1; i < prices.size(); i++) {

            // STEP 3: If price increased,
            // take that profit
            if(prices[i] > prices[i - 1]) {

                profit += prices[i] - prices[i - 1];
            }
        }


        // STEP 4: Return total profit
        return profit;
    }
};
//time complexit = O(n)
//Space Comlexity = O(1)