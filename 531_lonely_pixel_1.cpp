/*Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:
The range of width and height of the input 2D array is [1,500].*/
class Solution {
  //Go
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
      int row = picture.size();
      if(row == 0) {
        return 0;
      }
      int col = picture[0].size();
      vector<int> rowB(row,0);
      vector<int> colB(col,0);
      int lonelyB = 0;
      //count the number of B in each row and col
      for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
          if (picture[i][j] == 'B'){
            rowB[i]++;
            colB[j]++;
          }
        }
      }
      for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
          //if we encounter a B and if the row and col of that B has only 1 B in it so what we encountered would be a lonely B
          if (picture[i][j] == 'B' && rowB[i] == 1 && colB[j] == 1) {
            lonelyB++;
          }
        }
      }
      return lonelyB;
    }
};
