/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/
class Solution {
	//Ad_Mi_Fa_Al_Bl_Am_Go_Ap_Vm
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
        return 0;
      }
      int size = prices.size();
      vector<int> profitAtP(size,0);
      int maxp = 0;
      int curcost = prices[0];
      profitAtP[0] = 0;
      for (int i = 1; i<size; i++) {
        //change the currentcost if currprice is less than it
        if (prices[i] <= curcost) {
          curcost = prices[i];
        }  else {
          //if curprice is greater than  current cost, sell the stock and get the profit
          //now buy the stock at todays price and sell it again if the price falls below current price
          maxp = max(maxp,maxp + prices[i]-curcost);
          curcost = prices[i];
        }
      }
      return maxp;
    }
};
