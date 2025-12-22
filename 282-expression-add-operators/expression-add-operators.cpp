class Solution {
public:
    vector<string> result;
    void helper_backtrack(string& num, long target, int idx, long value, long prev, string expr){
        if(idx==num.size()){
            if(value==target) result.push_back(expr);
            return;
        }
        for(int i=idx;i<num.size();i++){
            if(i>idx && num[idx]=='0') break;
            long curr=stol(num.substr(idx,i-idx+1));
            if(idx==0) helper_backtrack(num,target,i+1,curr,curr,to_string(curr));
            else{
                helper_backtrack(num,target,i+1,value+curr,curr,expr+"+"+to_string(curr));
                helper_backtrack(num,target,i+1,value-curr,-curr,expr+"-"+to_string(curr));
                helper_backtrack(num, target, i + 1,value-prev+prev*curr,prev*curr,expr+"*"+to_string(curr));
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        helper_backtrack(num,target,0,0,0,"");
        return result;
    }
};