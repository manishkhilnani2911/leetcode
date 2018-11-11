/*Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].*/
class Solution {
  //Go_Bl_Am
public:
    vector<int> dailyTemperatures(vector<int>& T) {
      //move from right to left,
      //for each element check from the stack as to which element is greater than this element
      //if element is not greater pop it from the stack,
      //if found a greater element update entry for current element
      //while popping the elements it is safe to do this because for if the popped elements were greater than the left elements then if the current element is greater than all the popped elements then it is also greater than the elements to the left of the current elements
      stack<pair<int,int>> s;
      vector<int> res(T.size(),0);
      for (int i=T.size()-1; i>=0; i--) {
        //while the stack element is
        while(!s.empty() && s.top().first <= T[i]) {
          s.pop();
        }
        res[i] = s.empty() ? 0 : s.top().second - i;
        s.push(make_pair(T[i],i));
      }
      return res;
    }

  //slow solution
    /*vector<int> dailyTemperatures(vector<int>& T) {
      //for each i, get the next highest element
      vector<int> res;
      for (int i=0;i<T.size();i++) {
        int j = i+1;
        bool found = false;
        while(j<T.size()) {
          if (T[j] > T[i]) {
            found = true;
            break;
          }
          j++;
        }
        if (found) {
          res.push_back(j-i);
        } else {
          res.push_back(0);
        }
      }
      return res;
    }*/
};
