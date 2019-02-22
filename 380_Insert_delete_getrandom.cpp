/*Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();*/
class RandomizedSet {
  //Go_Bl_Am_Li_Fa_Ub_Mi_Wa_Ye_Qu_Tw_Ap
  unordered_map<int,int> m;
  vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      if (m.find(val) != m.end()) {
        return false;
      }
      //insert into the map and add its index as the value
      m[val] = v.size();
      v.push_back(val);
      return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      if (m.find(val) == m.end()) {
        return false;
      }
      //move the value to be removed at the back of the vector and move the value at the back of the vector to the index at which the value to be deleted is stored
      v[m[val]] = v.back();
      //now since the back value is stored at the index of the to be deleted value we need to make the same change in the map also
      m[v.back()] = m[val];
      v.pop_back();
      m.erase(val);
      return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
      return v[rand() % v.size()] ;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
