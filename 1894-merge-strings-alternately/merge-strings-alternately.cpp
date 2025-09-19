class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        int n1 = word1.size(), n2 = word2.size();

        // Merge characters alternately
        while (i < n1 && j < n2) {
            result.push_back(word1[i++]);
            result.push_back(word2[j++]);
        }

        // Append remaining characters from word1
        while (i < n1) {
            result.push_back(word1[i++]);
        }

        // Append remaining characters from word2
        while (j < n2) {
            result.push_back(word2[j++]);
        }

        return result;
    }
};
