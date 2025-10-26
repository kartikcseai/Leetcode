class MyHashMap {
public:
    map<int, int> m;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        m[key]=value;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            return m[key];  // Return value if key exists
        }
        return -1;  // Return -1 if key does not exist
    }
    
    void remove(int key) {
        m.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */