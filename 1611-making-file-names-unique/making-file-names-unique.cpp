class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> result;
        for(auto &n:names){
            if(mp.find(n)==mp.end()){ // Name not used -> use directly
                result.push_back(n);
                mp[n]=1;
            }
            else{ // Name exists -> find next available unique name
                int k=mp[n];// kitni baar aaya hai 
                string new_name=n+"("+to_string(k)+")";
                while(mp.find(new_name)!=mp.end()){
                    k++;
                    new_name=n+"("+to_string(k)+")";
                }
                result.push_back(new_name);
                mp[n]=k+1; // next available for base name
                mp[new_name]=1; // mark new name as used
            }
        } 
        return result;
    }
};