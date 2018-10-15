/*You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.*/
class Solution {
	//Go_Am_Mi
public:
    string getHint(string secret, string guess) {
      vector<int> s(10,0);
      vector<int> g(10,0);
      int bull = 0;
      int cow = 0;
      for (int i=0;i<secret.length();++i) {
        if (secret[i] == guess[i]) {
          bull++; //if the character matches and is at the same position increase bull count
        } else {
          //if the character doesnt match then recored the character
          s[secret[i] - '0']++;
          g[guess[i] - '0']++;
        }
      }
      //see for each missed guess how many time the character was present in the secret string
      for(int i=0;i<g.size();i++){
        if (g[i] > 0) { //for each wrong guess , if the character was present in the secret string
          if (s[i] > 0) { //add the minimum count for the cow count
            //eg1 s = 3214 g = 1221 the count of unmatched 1 in guess is 2 but it only occurs 1 time in secret so we add only one
            //eg2 s = 1211 g = 3221 the count of unmatched 1 in secret is 2 but in guess its 0 so we need to add only one,
            //in general add the minimum of the two
            cow += g[i] < s[i] ? g[i] : s[i];
          }
        }
      }
      string ans = to_string(bull) + "A" + to_string(cow) + "B";
      //cout<<bull<<" "<<cow<<"\n";
      return ans;
    }
};
