/*You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.*/
class Solution {
  //Am
public:
    int calPoints(vector<string>& ops) {
      //if its integer push value on to the stack, else if C pop the top most value
      //if its D then push 2*top() of stack
      //return sum of all value on the stack
      if (ops.size() == 0) {
        return 0;
      }
      stack<int> res;
      for(auto s : ops) {
        if (s == "C") {
          //if stack not empty pop top element
          if (!res.empty()) {
            res.pop();
          }
        } else if (s == "D") {
          //push two times the last value on to the stack
          if (!res.empty()) {
            res.push(2*res.top());
          }
        } else if (s == "+") {
          //extract top two element and push sum of these two elements
          if (res.size()>=2) {
            int first = res.top();
            res.pop();
            int second = res.top();
            res.pop();
            res.push(second);
            res.push(first);
            res.push(first+second);
          }
        } else {
          res.push(stoi(s));
        }
      }
      int count = 0;
      while(!res.empty()) {
        count += res.top();
        res.pop();
      }
      return count;
    }
};
