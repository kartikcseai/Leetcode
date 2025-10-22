class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        
        for (const string& str : strs) {
            // Approach 1: Sort the string and use it as a key
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // Sorting the string
            anagramMap[sortedStr].push_back(str);
        }
        
        // Collect the results from the map
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};