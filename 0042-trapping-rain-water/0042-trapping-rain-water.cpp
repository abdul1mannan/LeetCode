class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int res=0;
        int leftMax=LLONG_MIN;
        int rightMax=LLONG_MIN;
        while(l<=r){
            if(height[l]<=height[r]){
               if(height[l]>leftMax){
                leftMax=height[l];
               }
               else{
                res+=(leftMax-height[l]);
               }
               l++;
            }
             else{
               if(height[r]>rightMax){
                rightMax=height[r];
               }
               else{
                res+=(rightMax-height[r]);
               }
               r--;
            }
        }
        return res;

    }
};