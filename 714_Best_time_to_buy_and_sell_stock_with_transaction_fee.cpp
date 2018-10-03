/*Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/
class Solution {
  //Go_Fa_Bl
public:
    int maxProfit(vector<int>& prices, int fee) {
      int size = prices.size();
      if (size==0){
        return 0;
      }
      
      vector<int> buy(size,0); //this represents the total profit at any day i considering we are buying the stock at that day
      vector<int> sell(size,0); //this represents the total profit at any day i considering we are selling the stock at that day
      buy[0] = -prices[0]-fee; //since first day we cannot sell any stock since we dont have any 
      sell[0] = 0; //no stock to cell on that day so total profit is 0 at day 1
      
      for(int i=1; i<size; i++) {
        //if we buy at any day then we sold it on the day before and need to reduce the current price from total profit from selling the stock the previous day
        //or we bought the stock at the previous day and did nothing on the current day(hold the stock)
        buy[i] = max(buy[i-1],sell[i-1]-prices[i]-fee);
        //for selling we can do the following two things
        //1. bought the stock on previous day and sold it today, so add current price to the profit at day i-1 which was buy[i-1]
        //2. or do nothing
        sell[i] = max(sell[i-1],buy[i-1] + prices[i]);
      }
      return sell[size-1];  
    }
}; 
