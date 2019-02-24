/*
 Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 */
/*class Solution {
  //Go_Fa
public:
    string nextClosestTime(string time) {
        set<char> sorted;
        for(auto c:time){
            if(c==':') continue;
            sorted.insert(c);
        }

        string res = time;
        for(int i = time.size() -1; i>=0; i--){
            if(time[i] == ':' ) continue;
            auto it = sorted.find(time[i]);
             if(*it != *sorted.rbegin()){// not the largest number
                it++; // go to the next element
                res[i] = *it;
                if((i>=3 && stoi(res.substr(3,2))<60) ||(i<2&&stoi(res.substr(0,2))<24))
                    return res;
             }
             res[i]=*sorted.begin(); // take the smallest number
        }
        return res;
    }
};*/
class Solution {
  //Go_Fa
public:
    string nextClosestTime(string time) {
        set<char> sorted;
      //store all the numbers in the time in the set.
        for(auto c:time){
            if(c==':') continue;
            sorted.insert(c);
        }

        string res = time;
      //start from the last digit, if the last digit is not the largest digit then replace it with a number larger than that digit
      //if the number formed is a valid time this is the anser,
      //if the number formed is not valid or the last digit is the largest digit, change it to the smallest digit.
        for(int i = time.size() -1; i>=0; i--){
            if(time[i] == ':' ) continue;
            auto it = sorted.find(time[i]);
             if(*it != *sorted.rbegin()){// not the largest number
                it++; // go to the next element
                res[i] = *it;
                if((i>=3 && stoi(res.substr(3,2))<60) ||(i<2&&stoi(res.substr(0,2))<24))
                    return res;
             }
             res[i]=*sorted.begin(); // take the smallest number
        }
        return res;
    }
};
