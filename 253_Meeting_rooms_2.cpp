/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
  //Fa_Mi_Go_Am_Bl_Ub_Or_Ci
  //1. sort intervals by starting point
  //2. add the end time of the first meeting time into a min heap
  //3. for each successive meeting interval if the top of the heap is less than the current meeting start time
  //i.e., the earlist meeting end would end before than the current meeting can start, so remove current top of heap and
  // add the end time of current meeting to the min_heap.
  //4. return the heap size at the end of all interval iterations
public:
    static bool compare(Interval& a, Interval& b) {
      return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
      if(intervals.size() == 0) {
        return 0;
      }
      std::sort(intervals.begin(),intervals.end(),compare);
      priority_queue<int, vector<int>, greater<int>> min_heap;

      for (auto &x : intervals) {
        if (!min_heap.empty() && min_heap.top() <= x.start) {
          min_heap.pop();
        }
        min_heap.push(x.end);
      }
      return min_heap.size();
    }
};
