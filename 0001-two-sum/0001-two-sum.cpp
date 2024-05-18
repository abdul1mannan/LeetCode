class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>c;
        int index=0;
        int rem=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            rem=target-num;
            if(c.find(rem)!=c.end()){
               index=i;
            break;
            }
            else c[num]=i;
        }
        
// for(int i=0; i<nums.size(); i++){

//             for(int j=i+1; j<nums.size(); j++){

//             if(nums[i]+nums[j]==target){
//                 return {i,j};
//             }
//             }
//         }
//         return {};
        return {c[rem],index};
    }
};