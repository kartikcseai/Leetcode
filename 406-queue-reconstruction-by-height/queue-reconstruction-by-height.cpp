class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort people: first by height in descending order, then by k in ascending order
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> result;
        // Insert each person into the result array at the specified index
        for (const auto& person : people) result.insert(result.begin() + person[1], person);
        return result;
    }
};