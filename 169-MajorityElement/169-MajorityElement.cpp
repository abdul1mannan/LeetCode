// Last updated: 10/1/2025, 12:49:32 AM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int element=0;
        for(int i=0;i<n;i++){
            if(count==0){
                element=nums[i];
            }
            if(nums[i]==element){
                count++;
            }
            else count--;
        }
        return element;
    }
};