class Solution {
public:
    int minimumDeletions(string s) {
        int count_of_b = 0;
        int deletions = 0;
        for(char ch : s){
            if(ch == 'b') count_of_b++;
            else deletions = min(deletions + 1, count_of_b);
        }
        return deletions;
    }
};