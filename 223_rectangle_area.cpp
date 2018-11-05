/*Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.*/
class Solution {
  //Mi_Am_Go
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
      int res = 0;
      res = ((C-A)*(D-B)) + ((G-E)*(H-F));
      //if not over lapping return the sum of individual areas
      if (E >= C || //right
          G <= A || //left
          F >= D || //up
          H <= B) {//down
        return res;
      }
      //if they are overlapping subtract the overlapped area from res
      int overlap_area = abs((min(C,G) - max(A,E))* (max(F,B)-min(H,D))) ;
      return res-overlap_area;


    }
};
