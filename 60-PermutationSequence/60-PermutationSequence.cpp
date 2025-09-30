// Last updated: 10/1/2025, 12:50:47 AM
class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial=1;
        vector<int>ans;
        for(int i=1;i<n;i++){
            factorial=factorial*i;
            ans.push_back(i);
        }
        ans.push_back(n);
        k=k-1;
        string s="";
        while(true){
            s=s+to_string(ans[k/factorial]);
            ans.erase(ans.begin()+k/factorial);
            if(ans.size()==0){
                break;
            }
            k=k%factorial;
            factorial=factorial/ans.size();
        }
        return s;
    }
};