/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true*/
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
  //Am_Fa_Mi_Ye_Go_Li_Tw_Bl_Air_Sn
public:
    static bool compare(Interval a, Interval b) {
      return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
      if (intervals.size() == 0) {
        return true;;
      }
       //if the meeting times do not overlap the person can attend all the meetings
      //sort the intervals based on their starting time
      sort(intervals.begin(),intervals.end(),compare);
      for (int i=0; i<intervals.size()-1; i++) {
        if (intervals[i].end > intervals[i+1].start) { //[1,5] and [2,6] or [1,5] and [2,3]
          return false;
        }
      }
      return true;
    }
};
