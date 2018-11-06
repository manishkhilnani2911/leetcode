/*Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.*/
class Solution {
  //Go_Fa
public:
    int repeatedStringMatch(string A, string B) {
      //check if all of B letters are in A
      string AA = A;
      int count = 1;
      //keeping adding A till its length becomes greater than B
      while(AA.length() < B.length()) {
        AA += A;
        count += 1;
      }
      //find B in A
      if (AA.find(B) != string::npos)
        return count;
      AA = AA + A;
      //if not found, find B in AA by adding A one more time
      if (AA.find(B) != string::npos)
        return count+1;
      return -1;
    }
};
