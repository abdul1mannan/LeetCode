class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]*=-1;
        }

        sort(nums.begin(),nums.end());

        long long res=0;
        for(int i=0,j=0;i<n;i++){
            int lim=2*nums[i];
            while(j<n && nums[j]<=lim) ++j;

            res+=j-i-1;
        }
        return res;
    }
};