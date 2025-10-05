class Solution {
public:
    int reverse(int x) {
        bool neg = (x < 0);                   
        long long val = llabs((long long)x);  // safely take absolute value
        string s = to_string(val);

        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        long long num = stoll(s); // use long long to avoid overflow

        if (neg) num = -num;

        // check 32-bit signed integer overflow
        if (num < INT_MIN || num > INT_MAX) return 0;

        return (int)num;
    }
};
