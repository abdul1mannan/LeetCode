// Last updated: 10/1/2025, 12:48:22 AM
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
         sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b)     {
        return a[1] < b[1];
    });
        int count=1;
        int n=pairs.size();
        int end=pairs[0][1];
        for(int i=1;i<n;i++){
            
            if(pairs[i][0]>end){
                end=pairs[i][1];
                count++;
            }
        }
        return count;
        
        
    }
};