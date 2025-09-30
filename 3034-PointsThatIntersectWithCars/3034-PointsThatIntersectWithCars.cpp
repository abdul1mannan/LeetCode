// Last updated: 10/1/2025, 12:46:57 AM
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        map<int,int>car;
        for(auto&i:nums){
        car[i[0]]++;
        car[i[1]+1]--;
        }
         int ans =0;
    int count =0;
    for(int i =1; i <101; ++i){
        count += car[i];
        if(count > 0){
            ++ans;
        }
    }
    return ans;
        
    }
};