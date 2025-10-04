class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n - 1;
        int water = 0;
        while(l<r){
             if(height[l]<=height[r]){
                water=max(water,(height[l]*(r-l)));
                l++;
             }
             else {
                water=max(water,(height[r]*(r-l)));
                r--;
             }
        }
        return water;
    }
};