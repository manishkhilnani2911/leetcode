/*Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/
class Solution {
  //Mi_Ya_Ap_Am_Nv_Te_Bl_Ad
public:
    int countPrimes(int n) {
      if (n<=2) {
        return 0;
      }
      vector<int> prime(n+1,true);
      //only running till sqrt(n) since for any number from 2 to n
      //if we are not able to find a divisor till sqrt(number) we will not be able to find a divisor after sqrt(num)
      prime[0] = false;
      prime[1] = false;
      for (int i=2;i*i<n;i++) {
        for (int j=i*i;j<n;j=j+i) {
          if (prime[j]) {
            prime[j] = false;
          }
        }
      }
      prime[n] = false;
      int count = 0;
      for (auto i : prime) {
        if (i) {
          count++;
        }
      }
      return count;
    }
};
