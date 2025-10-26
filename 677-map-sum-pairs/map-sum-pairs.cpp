class MapSum {
public:
    map<string, int> m;
    MapSum() {
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string prefix) {
        int total = 0;
        // Iterate over all key-value pairs in the map
        for (const auto& pair : m) {
            if (pair.first.find(prefix) == 0) {  // Check if the key starts with the prefix
                total += pair.second;
            }
        }
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */