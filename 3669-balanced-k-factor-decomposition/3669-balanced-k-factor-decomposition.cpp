class Solution {
    int bestDiff=INT_MAX;
    vector<int> bestResult;
    void dfs(int n,int k, int start, vector<int>&curr){
        if(k==1){
            if(n>=start){
                curr.push_back(n);
                check(curr);
                curr.pop_back();
            }
            return;
        }
        for(int i=start;i<=n;i++){
            if(n%i==0){
                curr.push_back(i);
                dfs(n/i,k-1,i,curr);
                curr.pop_back();
            }
        }
    }

    void check(vector<int>&curr){
        int mini=*min_element(curr.begin(),curr.end());
        int maxi=*max_element(curr.begin(),curr.end());
        if(maxi-mini<bestDiff){
           bestDiff=maxi-mini;
           bestResult=curr;
        }
    }

public:
    vector<int> minDifference(int n, int k) {
        vector<int>curr;
        dfs(n, k, 1, curr);
        return bestResult;
    }
};
