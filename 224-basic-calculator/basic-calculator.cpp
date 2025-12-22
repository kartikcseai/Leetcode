class Solution {
public:
    int calculate(string s) {
        int res=0, sign=1;
        long num=0;
        stack<int> st;
        for (char c:s) {
            if(isdigit(c)) num=num *10+(c-'0');
            else if(c=='+'){
                res+=sign*num;
                num=0;
                sign=1;
            } 
            else if(c=='-') {
                res+=sign*num;
                num=0;
                sign=-1;
            } 
            else if(c=='(') {
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            } 
            else if(c==')') {
                res+=sign*num;
                num=0;
                res*=st.top(); st.pop(); 
                res+=st.top(); st.pop();
            }
        }
        res+=sign*num; 
        return res;
    }
};
