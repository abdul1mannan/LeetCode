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
    for(int i =1; i <102; ++i){
        count += car[i];
        if(count > 0){
            ++ans;
        }
    }
    return ans;
        
    }
};