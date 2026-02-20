class Solution {
public:
    bool helper_isMatch(string s, string p){
        if(p.length() == 0) return s.length() == 0;
        bool first_char = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        if(p.length() >= 2 && p[1] == '*'){
            bool not_take = helper_isMatch(s, p.substr(2));
            bool take = first_char && helper_isMatch(s.substr(1), p);
            return not_take || take;
        }
        else return first_char && helper_isMatch(s.substr(1), p.substr(1));
    }

    bool isMatch(string s, string p) {
        return helper_isMatch(s, p);
    }
};