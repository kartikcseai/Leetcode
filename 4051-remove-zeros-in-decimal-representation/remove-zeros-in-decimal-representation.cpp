class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string a = "";
        for(int i=0;i<s.size();i++){
            if(s[i]!='0') a.push_back(s[i]); 
        }
        long long ans = stoll(a);
        return ans;
    }
};