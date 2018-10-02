/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/
class Solution {
  //Fa_Bl_Am_Go_Mi_Ad_Ap_Ly_Vm_Pa_Ye_Ya_Pa_Ba_Eb_Ub_Al_Nv
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
        //if at any index the price goes down the last purchase price update the cost
        //basically we are just finding the minimum number in the array which has atleast one increasing number after it
        if (prices[i] < curcost) {
          curcost = prices[i];
        }  else {
          //keep updating the profit if we find the price higher than the current price
          maxp = max(maxp,prices[i]-curcost);
        }
      }
      return maxp;
    }
};
