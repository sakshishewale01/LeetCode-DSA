class Solution {
public:

    int maxProfit(vector<int>& prices) {

        // STEP 1: Assume first price is
        // the minimum buying price
        int minPrice = prices[0];

        // STEP 2: Store the maximum profit
        int maxProfit = 0;


        // STEP 3: Check every price
        for(int i = 1; i < prices.size(); i++) {

            // STEP 4: Calculate profit
            // if we buy at minPrice
            // and sell today
            int profit = prices[i] - minPrice;


            // STEP 5: Update maximum profit
            maxProfit = max(maxProfit, profit);


            // STEP 6: Update minimum buying price
            minPrice = min(minPrice, prices[i]);
        }


        // STEP 7: Return best profit
        return maxProfit;
    }
};