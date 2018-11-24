/*Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]*/
class Solution {
  //Ap_Go_Mi_Bl_Fa_Qu_Li_IBM_Ad_Am_vm_Ya_Or_Pa_Eb_SA
public:
    vector<string> fizzBuzz(int n) {
      int i=1;
      vector<string> res;
      if (n==0) {
        return res;
      }
      int x = 3, y = 5;
      while(i<=n) {
        x--;
        y--;
        if (x==0 && y==0) {
          res.push_back("FizzBuzz");
          x=3;
          y=5;
        } else if (x == 0) {
          res.push_back("Fizz");
          x=3;
        } else if (y == 0) {
          res.push_back("Buzz");
          y=5;
        } else {
          res.push_back(to_string(i));
        }
        i++;
      }
      return res;
    }
};
