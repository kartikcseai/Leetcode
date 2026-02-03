class LRUCache {
public:
    int capacity;
    list<pair<int,int>> doubly_linkedlist;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        doubly_linkedlist.splice(doubly_linkedlist.begin(), doubly_linkedlist, mp[key]);
        return mp[key]->second;
    }
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            doubly_linkedlist.splice(doubly_linkedlist.begin(), doubly_linkedlist, mp[key]);
            mp[key]->second = value;
        }   else{
                if(doubly_linkedlist.size() == capacity) {
                    auto last = doubly_linkedlist.back();
                    mp.erase(last.first);
                    doubly_linkedlist.pop_back();
                }
            doubly_linkedlist.push_front({key, value});
            mp[key] = doubly_linkedlist.begin();
        }
    }
};