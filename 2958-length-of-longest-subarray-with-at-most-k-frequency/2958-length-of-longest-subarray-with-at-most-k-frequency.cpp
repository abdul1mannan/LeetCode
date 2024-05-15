class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        map<int,int>freq;
        int n=nums.size();
        int count=0;
        int maxi=0;
        int j=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==k+1){
                while(freq[nums[i]]==k+1){
                    --freq[nums[j]];
                    ++j;
                }
               count=i-j+1;
                
            }
            else count++;
            
           maxi=max(maxi,count);
        }
        return maxi;
    }
};