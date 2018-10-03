/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]*/
class Solution {
public:
     int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0){
          return 0;
        }
      vector<int> buy(size,0); //profit at ith day that results in buying of the stock
      vector<int> sell(size,0); //profit at ith day that results in selling of the stock
      buy[0] = -prices[0];
      sell[0];

      for(int i = 1; i<size; i++) {
        if (i == 1) {
          //for any given day we can either hold the stock, so no action taken today so we would have bought the stock at i-1'th day
          //so the profit would be buy[i-1] or we would have bought the stock after cooldown
          buy[i] = max(buy[i-1],0 - prices[i]);
        } else {
          buy[i] = max(buy[i-1],sell[i-2] - prices[i]);
        }
        //for sell we either do nothing on this day or sell the stock
        sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
      }
      return sell[size-1];
    }
};
