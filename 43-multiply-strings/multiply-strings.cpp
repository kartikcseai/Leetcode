class Solution {
public:
    string multiply(string num1, string num2) {
        // Edge case: If either number is "0", return "0"
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int len1 = num1.size(), len2 = num2.size();
        // Result can have at most len1 + len2 digits
        vector<int> result(len1 + len2, 0);

        // Perform multiplication
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert the result vector to string, skipping leading zeros
        string result_str = "";
        for (int num : result) {
            if (!(result_str.empty() && num == 0)) {  // Skip leading zeros
                result_str += to_string(num);
            }
        }

        return result_str;
    }
};