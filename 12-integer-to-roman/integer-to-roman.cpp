class Solution {
public:
    string intToRoman(int num) {
        // Fixed arrays of values and their Roman symbols
        int values[]   = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        int n = sizeof(values) / sizeof(values[0]);  // length of arrays

        for (int i = 0; i < n; i++) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];  // append the matching symbol
            }
        }
        return result;
    }
};