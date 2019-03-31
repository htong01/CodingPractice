O(1) time complexity:
  - fast get: hashtable
  - fast evict: double linked list - iterate over the hashmap instead of using linkedlist
O(n) in space complexity


unordered_map: count() is implemented as return (find(__k) != end());
iterate over: unordered_map<int, list<int>::iterator> mp


class LRUCache {
    int size;
    list<int> lru;
    unordered_map<int, int> kv; // key->value
    unordered_map<int, list<int>::iterator> mp; // key->iterator
public:
    LRUCache(int capacity) : size(capacity){
    }
    
    int get(int key) {
        if(kv.count(key) == 0) return -1;
        update(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if(kv.count(key) == 0 && kv.size() == size)
            evict();
        update(key);
        kv[key] = value;
    }
    void update(int key){
        if(kv.count(key)) lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    void evict(){
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
};
