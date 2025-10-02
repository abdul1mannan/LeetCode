class Solution {
public:
    int minOperations(string s) {
        int mini=200;
        for(auto it:s){
            if(it=='a'){
                continue;
            }
            if(it<mini){
                mini=it;
            }
        }
        if(mini==200){
            return 0;
        }
        else {
            int cnt='z'-mini+1;
            return cnt;
        }
    }
};