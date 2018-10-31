/*Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false*/
class TwoSum {
  //Li_Fa
  unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
  //keeping increasing the number count
    void add(int number) {
      m[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
      for (unordered_map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
        int first = it->first;
        int second = value-first;
        //check below two condition,
        //1. if both numbers are equal then their count should be greater than 1
        //2. if the numbers are not equal then the second number should be present in the map
        if (first == second && it->second > 1 || first!=second && m.find(second) != m.end()) {
          return true;
        }
      }
      return false;

    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
