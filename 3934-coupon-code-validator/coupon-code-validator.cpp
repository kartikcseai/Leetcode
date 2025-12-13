class Solution {
public:
    bool isValidCode(const string& code) {
        if (code.empty()) return false;
        for (char c : code) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        vector<pair<int, string>> valid;
        for (int i=0;i<code.size();i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            if (priority.count(businessLine[i])==0) continue;
            valid.push_back({priority[businessLine[i]],code[i]});
        }
        sort(valid.begin(),valid.end(),[](auto& a,auto& b) {
            if (a.first!=b.first) return a.first<b.first;
            return a.second<b.second;
        });
        vector<string> result;
        for (auto& p:valid) result.push_back(p.second);
        return result;
    }
};
