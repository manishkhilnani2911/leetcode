/*Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

Example:
Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

Note:
The range of width and height of the input 2D array is [1,200].*/
class Solution {
  //Go
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
      int row = picture.size();
      if (row == 0) {
        return 0;
      }
      int col = picture[0].size();
      cout<<"here1\n";
      //vectors to store for each row and col the indexes of the B's
      vector<set<int>> rowB(row);
      vector<set<int>> colB(col);
      int lonelyB =  0;
      for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          if (picture[i][j] == 'B'){
            rowB[i].insert(j);
            colB[j].insert(i);
          }
          //cout<<rowB[i].size()<<" "<<colB[j].size()<<"\n";
        }
      }
      cout<<"here\n";
      for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          //if we find any 'B' se if the row and col of that B has exactly N B's
          if (picture[i][j] == 'B' && rowB[i].size() == N && colB[j].size() == N) {
            //for each entry in col[j] we have the rows which have B in the same col, they should all be the same
            bool lonely = true;
            for (auto r : colB[j]) {
              if (picture[i] != picture[r]) {
                lonely = false;
                break;
              }
            }
            lonelyB += lonely;
          }
        }
      }
      return lonelyB;
    }
};
