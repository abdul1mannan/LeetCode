// Last updated: 10/1/2025, 12:51:12 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=1;
        int cnt=1;
        for(int i=1;i<n;i++){
          if(nums[i-1]==nums[i]){
            continue;
          }
          else {
            nums[j]=nums[i];
            j++;
            cnt++;
          }
        }
        return cnt;
    }
};