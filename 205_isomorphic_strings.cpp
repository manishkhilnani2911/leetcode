/*
 Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
 */
class Solution {
  //Go_Li_Bl_Ye_Ya_Am_Sa_Mi
public:
  /*
  The idea is that we need to map a char to another one, for example, "egg" and "add", we need to constract the mapping 'e' -> 'a' and 'g' -> 'd'. Instead of directly mapping 'e' to 'a', another way is to mark them with same value, for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.

So we use two arrays here m1 and m2, initialized space is 256 (Since the whole ASCII size is 256, 128 also works here). Traverse the character of both s and t on the same position, if their mapping values in m1 and m2 are different, means they are not mapping correctly, returen false; else we construct the mapping, since m1 and m2 are both initialized as 0, we want to use a new value when i == 0, so i + 1 works here.
  */
    bool isIsomorphic(string s, string t) {
        //int a1[128] = {0}, a2[128] = {0};
        vector<int> a1(128,0);
        vector<int> a2(128,0);
        for(int i = 0; i<s.size(); i++){
            if(a1[s[i]] != a2[t[i]]){
                return false;
            } else if(!a1[s[i]] && !a2[t[i]]) {
                a1[s[i]] = i+1;
                a2[t[i]] = i+1;
            }
        }
        return true;
    }
};
