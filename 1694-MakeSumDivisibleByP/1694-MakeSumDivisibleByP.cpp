// Last updated: 10/1/2025, 12:47:22 AM
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

    int totalSum = 0;


    for (int num : nums) {

        totalSum = (totalSum + num) % p;

    }



    if (totalSum == 0) {

        return 0;

    }

    
    unordered_map<int, int> prefixModMap;

    prefixModMap[0] = -1;  
    int prefixSum = 0;

    int minLen = n;

    for (int i = 0; i < n; ++i) {

        

        prefixSum = (prefixSum + nums[i]) % p;

        

        int target = (prefixSum - totalSum + p) % p;

        

        if (prefixModMap.find(target) != prefixModMap.end()) {

            minLen = min(minLen, i - prefixModMap[target]);

        }

        

        prefixModMap[prefixSum] = i;

    }

    

    return minLen == n ? -1 : minLen;

}
    
};