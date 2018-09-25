/*Implement an iterator to flatten a 2d vector.

Example:

Input: 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]
Output: [1,2,3,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,2,3,4,5,6].
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.*/
class Vector2D {
  //Am_Go_Fa_Ub
  queue<int> s;
  void flatten(vector<int> x) {
    for (auto i : x){
      s.push(i);
    }
  }
public:
    Vector2D(vector<vector<int>>& vec2d) {
      for (int i=0;i<vec2d.size();i++) {
        flatten(vec2d[i]);
      }
    }

    int next() {
      int a = s.front();
      s.pop();
      return a;
    }

    bool hasNext() {
      return !s.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
