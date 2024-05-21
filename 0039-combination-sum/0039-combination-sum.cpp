class Solution {
public:
    void subsetsum(int ind,int n,vector<int>&d,vector<vector<int>>&ans,vector<int>&candidates,int target,int sum){
        if(ind==n){
         if(sum==target){
            ans.push_back(d);
        }return ;
            
        }
     
        if(sum<=target){
        d.push_back(candidates[ind]);
        subsetsum(ind,n,d,ans,candidates,target,sum+candidates[ind]);
        d.pop_back();
        }
        subsetsum(ind+1,n,d,ans,candidates,target,sum);
       
          
        }
        
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>d;
        int n=candidates.size();
        int sum=0;
        subsetsum(0,n,d,ans,candidates,target,sum);
        return ans;
    }
};