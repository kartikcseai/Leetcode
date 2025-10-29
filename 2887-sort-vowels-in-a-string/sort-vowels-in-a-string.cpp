class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};  
        string v;
        for(char c:s){
            if(vowels.find(c)!=vowels.end()) v.push_back(c);
        }
        sort(v.begin(), v.end());
        string t="";
        int j=0;
        for(char c:s){
            if(vowels.find(c)!=vowels.end()) t.push_back(v[j++]);
            else t.push_back(c);
        }
        return t;

    }
};