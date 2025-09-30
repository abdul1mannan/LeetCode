// Last updated: 10/1/2025, 12:46:46 AM
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        
        int n =tasks.size();
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            int val=tasks[i][0]+tasks[i][1];
            mini=min(mini,val);
        }
        return mini;
    }
};