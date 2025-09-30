// Last updated: 10/1/2025, 12:46:54 AM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xorr=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xorr=xorr^grid[i][j];
            }
        }
        for(int i=1; i<=n*n;i++){
            xorr=xorr^i;
        }
      int number=xorr&(~(xorr-1));
        int zero=0;
        int one=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if((grid[i][j]&number)!=0){
                   one=one^grid[i][j];
             }
                else{
                    zero=zero^grid[i][j];
                }
            }
        }
         for(int i=1; i<=n*n;i++){
            if((i&number)!=0){
                one=one^i;
            }
             else zero=zero^i;
        }
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==zero) count++;
            }
        }
        if(count==2){
            return {zero,one};
        }
        else return {one,zero};
    }
};