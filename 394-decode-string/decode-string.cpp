class Solution {
public:
    string decodeString(string s) {
        stack<int> current_stack;
        stack<string> string_stack;
        string current="";
        int num=0;
        for(char c:s){
            if(isdigit(c)) num=num*10+(c-'0');
            else if(c=='['){
                current_stack.push(num);
                string_stack.push(current);
                num=0;
                current="";
            }
            else if(c==']'){
                int k=current_stack.top();
                current_stack.pop();
                string temp=current;
                current=string_stack.top();
                string_stack.pop();
                while (k--) current+=temp;
            }
            else current+=c;
        }
        return current;
    }
};