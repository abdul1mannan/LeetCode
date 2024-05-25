class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        map<int,int>cream;
        for(auto &i:ranges){
            cream[i[0]]++;
            cream[i[1]+1]--;
            
        }
        int count=0;
        for(int i=0;i<51;i++){
            count+=cream[i];
            if(i>=left&& i<=right&&count<=0){
                return false;
            }
        }
        return true;
    }
};