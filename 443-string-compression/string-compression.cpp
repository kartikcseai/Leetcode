#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        for (int i = 0; i < n;) {
            char current = chars[i];
            int j = i;
            while (j < n && chars[j] == current) {
                j++;
            }
            int count = j - i;
            chars[write++] = current;
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
            i = j;
        }
        return write; 
    }
};
