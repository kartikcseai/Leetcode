class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If str1 + str2 is not equal to str2 + str1, there's no common divisor
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Calculate the GCD of the lengths of the two strings
        int gcdLength = gcd(str1.length(), str2.length());
        
        // Return the substring of str1 with length equal to the GCD of lengths
        return str1.substr(0, gcdLength);

    }
};