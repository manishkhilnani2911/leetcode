/*We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example :

Input: n = 10, pick = 6
Output: 6*/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
  //Go
public:
    int guessNumber(int n) {
      //guess the middle number
      //if number is smaller, guess from [middle_num+1,n]
      //else search from [0,middle_num-1]
      int start = 0;
      int end = n;
      int middle_num;
      while(true) {
        middle_num = (end - start)/2 + start;
        //cout<<"number is "<<middle_num<<"\n";
        int res = guess(middle_num);
        //cout<<res<<"\n";
        if (res == 0)
          return middle_num;
        if (res == -1) {
          //cout<<"number is smaller\n";
          end = middle_num - 1;
        }//number is smaller
        else //=1
          start = middle_num +  1;
      }
    }
};
