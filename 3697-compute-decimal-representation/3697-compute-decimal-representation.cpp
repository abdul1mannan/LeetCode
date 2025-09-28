class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long cnt = 1;
        while (n > 0) {
            int digit = n % 10;
            long long val = digit * cnt;
            cnt = cnt * 10;
            n = n / 10;
            if (digit == 0)
                continue;
            ans.push_back(val);
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};