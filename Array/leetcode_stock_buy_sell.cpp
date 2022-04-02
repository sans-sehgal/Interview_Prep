// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// think Kedane's algorithm 
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int> diff;
        for(int i=0; i<prices.size()-1; i++) 
            diff.push_back(prices[i+1] - prices[i]);
        int profit = 0;
        int curr_profit = 0;
        
        for(int i=0; i<diff.size(); i++)
        {
            curr_profit+=diff[i];
            if(curr_profit < 0)
                curr_profit = 0;
            else if(curr_profit > profit)
                profit = curr_profit;
        }
        return profit;
    }
};