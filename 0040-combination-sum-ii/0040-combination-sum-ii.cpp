class Solution {
public:
       void subsetsum(int ind,int n,vector<int>&d,vector<vector<int>>&ans,vector<int>&candidates,int target,int sum){
           
              if(sum==target){
            ans.push_back(d);
        }
        
           if(ind==n || sum>target){
               return ;
           }
        
         for (int i = ind; i < n; ++i) {
        if (i > ind && candidates[i] == candidates[i - 1]) {
            continue; 
          }
        d.push_back(candidates[i]);
        subsetsum(i + 1, n, d, ans, candidates, target, sum + candidates[i]);
        d.pop_back();
        }
       }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>d;
        int n=candidates.size();
        int sum=0;
        subsetsum(0,n,d,ans,candidates,target,sum);
        return ans;
         
    }
};