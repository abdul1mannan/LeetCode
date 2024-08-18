class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=0;
        int rmax=0;
        int l=0;
        int r=height.size()-1;
        int sum=0;
        while(l<r){
            
            if(height[l]<height[r]){
                if(lmax>height[l]){
                    sum+=lmax-height[l];
                }
                else lmax=height[l]; l++;
            }
            else{
                if(rmax>height[r]){
                    
                sum+=rmax-height[r];
                }
                else rmax=height[r]; r--;
            }
        }
        return sum;
    }
};