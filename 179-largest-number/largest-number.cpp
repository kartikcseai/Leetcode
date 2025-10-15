#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert all numbers to strings
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // Custom comparator
        sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        // Edge case: if the largest number is "0"
        if (arr[0] == "0") return "0";

        // Build the result
        string result;
        for (auto &s : arr) result += s;

        return result;
    }
};
