class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0,j=s.size()-1;
        while(j>=i){
            if(!isalpha(static_cast<unsigned char>(s[i]))) i++;
            else if(!isalpha(static_cast<unsigned char>(s[j]))) j--;
            else {
                swap(s[i],s[j]);
                i++; j--;
            }
        }
        return s;
    }
};