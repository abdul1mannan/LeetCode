class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        int m=friends.size();
        vector<int>ans;
        map<int,int>mpp;

        for(int i=0;i<m;i++){
            mpp[friends[i]]=1;
        }

        for(int i=0;i<n;i++){
            if(mpp[order[i]]==1)
            ans.push_back(order[i]);
        }
        return ans;
    }
};