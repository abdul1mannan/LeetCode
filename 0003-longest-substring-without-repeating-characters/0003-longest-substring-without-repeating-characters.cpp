class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);  
        int l = 0;
        int maxi = 0;

        for (int r = 0; r < (int)s.size(); r++) {
            char c = s[r];

            if (hash[c] != -1 && hash[c] >= l) {
                l = hash[c] + 1;  
            }

            hash[c] = r; 
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};
