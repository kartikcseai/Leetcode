class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());
        vector<vector<int>> L(half + 1), R(half + 1);
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    cnt++;}}
            L[cnt].push_back(sum);}
        for (int mask = 0; mask < (1 << half); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;}}
            R[cnt].push_back(sum);
        }
        for (int i = 0; i <= half; i++) sort(R[i].begin(), R[i].end());
        int ans = INT_MAX;
        for (int i = 0; i <= half; i++) {
            for (int s1 : L[i]) {
                int need = half - i;
                int target = total / 2 - s1;
                auto& vec = R[need];
                auto it = lower_bound(vec.begin(), vec.end(), target);
                if (it != vec.end()) {
                    int sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));}
                if (it != vec.begin()) {
                    --it;
                    int sum = s1 + *it;
                    ans = min(ans, abs(total - 2 * sum));}
            }
        }
        return ans;
    }
};
