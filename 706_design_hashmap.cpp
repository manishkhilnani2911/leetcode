/*Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 

Note:

All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.*/
class MyHashMap {
  //Mi_Li_Tw_Sa_Ap
public:
    struct hashNode {
        int _key, _val;
        hashNode *next;
        hashNode(int key, int value) : _key(key), _val(value), next(nullptr) {}
    };
    hashNode **table;
    /** Initialize your data structure here. */
    MyHashMap() {
        table = new hashNode*[10000];
        for (int i = 0; i < 10000; i++) {
            table[i] = nullptr;
        }
    }

    int getIndex(int key) {
      int temp = key % 10000;
      return temp;
    }

    /** value will always be non-negative. */
    /*void put(int key, int value) {
        int hashCode = key % 100;
        if (table[hashCode] == nullptr) {
            table[hashCode] = new ListNode(key, value);
            return;
        }

        ListNode *prev = nullptr, *curr = table[hashCode];
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new ListNode(key, value);
    }*/
    void put(int key, int value) {
      int index = getIndex(key);
      if (table[index] == NULL) {
        table[index] = new hashNode(key,value);
      } else {
        hashNode* prev = NULL, *curr = table[index];
        while(curr) {
          if (curr->_key == key) {
            curr->_val = value;
            return;
          }
          prev = curr;
          curr = curr->next;
        }
        prev->next = new hashNode(key,value);
      }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = getIndex(key);
        hashNode *curr = table[index];
        while (curr != nullptr) {
            if (curr->_key == key) {
                return curr->_val;
            }
            curr = curr->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = getIndex(key);
        if (table[index] == nullptr) {
            return;
        } else if (table[index]->_key == key) {
            table[index] = table[index]->next;
            return;
        }

        hashNode *prev = table[index], *curr = prev->next;
        while (curr != nullptr) {
            if (curr->_key == key) {
                prev->next = curr->next;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};
