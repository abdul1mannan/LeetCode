class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int h=height.size()-1;
        int res=0;
        int maxl=0;
        int maxh=0;
        
        while(l<=h){
            
            if(height[l]<=height[h]){
                
                if(height[l]<maxl)
                res+=maxl-height[l];
                else maxl=height[l];
               
                l++;
            }
            else {
                if(height[h]<maxh){
                    res+=maxh-height[h];
                }
                else maxh=height[h];
                
                h--;
            }
        }
        return res;
    }
};