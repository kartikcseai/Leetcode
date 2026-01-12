class Solution {
public:
    char next(char ch){
        if(ch=='a') return 'b';
        if(ch=='b') return 'c';
        return 'a';
    }
    int addMinimum(string word) {
        int ans=0;
        char expected='a';
        for(char i:word){
            while(i!=expected){
                ans++;
                expected=next(expected);
            }
            expected=next(expected);
        }
        while(expected!='a'){
            ans++;
            expected=next(expected);
        }
        return ans;
    }
};