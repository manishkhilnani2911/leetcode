/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache*///( 2 /* capacity */ );

/*cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4*/
class LRUCache {
  //Am_Bl_Mi_Fa_Ub_Ap_Go_Or_Li_Sa_Zi_Ba_Tw_Eb_Ya_Ad_Pa_Sn_Nv_Ci_Ly_Pi_Twit_Pa_Vm_Ali_Ye_Wa_Vi_In_Qu_Dr
  int _capacity;
  list<pair<int,int>> _l;
  unordered_map<int,list<pair<int,int>>::iterator> _m; //storing key and pointer to (key,value) pair in list
public:
    LRUCache(int capacity) : _capacity(capacity) {
    }

    int get(int key) {
      //search if key is in the map;
      auto it = _m.find(key);
      if (it == _m.end()) {
        //key not found return -1
        return -1;
      }
      //if found move it to the top of the list
      _l.splice(_l.begin(),_l,it->second); //move the element pointed by it->second to the top of list _l
      _m[key] = _l.begin();
      return it->second->second;
    }

    void put(int key, int value) {
      auto it = _m.find(key);
      if (it != _m.end()) {
        //already in the map, bring it to the top of the list
        _l.splice(_l.begin(),_l,it->second);
        //update its value
        it->second->second = value;
      } else {
        //key is not present in the map
        //if we have hit the capacity, then remove the last entry of the map
        if (_m.size() == _capacity) {
          int key_to_del = _l.back().first;
          _l.pop_back();
          _m.erase(key_to_del);
        }
        _l.push_front(make_pair(key,value));
        _m[key] = _l.begin();
      }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
