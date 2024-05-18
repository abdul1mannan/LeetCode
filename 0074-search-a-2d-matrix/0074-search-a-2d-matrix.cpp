class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int length=m*n;
        int low=0;
        int high=length-1;
       
        while(low<=high ){
             int mid=(low+high)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            if(matrix[mid/m][mid%m]>target){
                high=mid-1;
            }
             if(matrix[mid/m][mid%m]<target){
                low=mid+1;
            }
        }
        return false;
    }
};