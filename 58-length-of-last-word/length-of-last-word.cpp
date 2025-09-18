class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1; 
        int length = 0;       

        //skip trailing spaces at the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        //count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};
