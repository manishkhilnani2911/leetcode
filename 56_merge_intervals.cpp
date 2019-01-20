/*Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.*/

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
	//Fa_Go_Bl_Ub_Mi_Li_Am_Ap_Or_Ci_Ye_Tw_Sa_Ya_Nv_Dr_Pin_Wa_Sap
private:
  vector<Interval> res;
public:
  static bool compareInt(Interval& x, Interval& y) {
      return x.start < y.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
      if (intervals.size() < 2) {
        return intervals;
      }
      //sort intervals based on the first elements
      std::sort(intervals.begin(),intervals.end(),compareInt);
      int i = 0;
      while(i<intervals.size()-1) {
        if (intervals[i+1].start > intervals[i].end) { //no overlap [1,2] & [3,4]
          i++;
        } else if (intervals[i+1].start <= intervals[i].end && intervals[i+1].end > intervals[i].end){ //overlap [1,4] & [3,5] resultant = [1,5]
          intervals[i].end = intervals[i+1].end;
          intervals.erase(intervals.begin() + (i+1));
        }  else { //[1,5] & [2,3] 2nd interval is inside 1st, do not need second
          intervals.erase(intervals.begin() + (i+1));
        }
      }
      return intervals;
    }

};
