/*Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  //Li_Go_Fa_Ap_Tw_Ub_Am_Mi
  queue<NestedInteger> s;
  void flattenList(vector<NestedInteger> &list) {
    for (auto i : list) {
      if (i.isInteger()) {
        s.push(i);
      } else {
        flattenList(i.getList());
      }
    }
  }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      //put everything as an integer in the queue
      //if the element in the nested list is an integer put it as it is, otherwise flatten the list and put all
      //the integer element in the stack
      flattenList(nestedList);
    }

    int next() {
      NestedInteger temp = s.front();
      s.pop();
      return temp.getInteger();
    }

    bool hasNext() {
      return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
