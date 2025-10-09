class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size();
int sum=0;
        for(int i=0;i<n;i++){
          sum+=(nums[i]*pow(-1,i));  
        }
        return sum;
    }
};