/*Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]*/
class Solution {
  //Go_Am
public:
  //sorting based on the fact that people with larger height are ahead
  //if two people have same height then one with fewer people in front of him/her is ahead
    static bool compare (pair<int,int> &a, pair<int,int> &b) {
      return ( (a.first > b.first) || (a.first == b.first && a.second < b.second));
    }
  //algo
  //1.sort according to above
  //2. now move people from starting , placing them at the index which is same as the number of people in front of them
  //this works because we keep on moving the smaller people which will not affect the position of the taller people
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
      sort(people.begin(),people.end(),compare);
      vector<pair<int,int>> res;
      for (auto &p : people) {
        res.insert(res.begin()+p.second,p);
      }
      return res;
    }
};
