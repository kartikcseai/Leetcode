class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string current;
        for(int i=0;i<=path.size();i++){
            if(i==path.size() || path[i]=='/'){
                if(current==".."){
                    if(!stack.empty()) stack.pop_back(); 
                }
                else if(!current.empty() && current!=".") stack.push_back(current);
                current.clear();
            }
            else current+=path[i];
        }
        string res="/";
        for(int i=0;i<stack.size();i++){
            res+=stack[i];
            if(i!=stack.size()-1) res+="/";
        }
        return res;
    }
};