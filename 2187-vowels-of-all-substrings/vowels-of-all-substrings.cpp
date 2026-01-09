class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    long long countVowels(string word) {
        long long ans=0;
        int n=word.size();
        for(int i=0;i<n;i++) if(isVowel(word[i])) ans+=(long long)(i+1)*(n-i);
        return ans;
    }
};