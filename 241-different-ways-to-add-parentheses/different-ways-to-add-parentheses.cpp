class Solution {
public:
    unordered_map<string,vector<int>> m;
    vector<int> diffWaysToCompute(string expression) {
        if(m.count(expression)) return m[expression];
        vector<int> res;
        for(int i=0;i<expression.size();i++){
            char c=expression[i];
            if(c=='+' || c=='-' || c=='*'){
                string left=expression.substr(0,i);
                string right=expression.substr(i+1);
                vector<int> l=diffWaysToCompute(left);
                vector<int> r=diffWaysToCompute(right);
                for(int a:l){
                    for(int b:r){
                        if(c=='+') res.push_back(a+b);
                        else if(c=='-') res.push_back(a-b);
                        else res.push_back(a*b);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        return m[expression]=res;
    }
};