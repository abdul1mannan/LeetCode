// Last updated: 10/1/2025, 12:47:18 AM
class Solution {
public:
    
    bool canWePlace(vector<int> &position, int dist, int ball,int n) {
    int balls = 1; 
    int last = position[0]; 
    for (int i = 1; i < n; i++) {
        if (position[i] - last >= dist) {
            balls++;
            last = position[i]; //update the last location.
        }
        if (balls >= ball) return true;
    }
    return false;
}
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int maximum=position[n-1]-position[0];
        int l=1;
        int h=maximum;
       
        while(l<=h){
             int mid=(l+h)/2;
            if(canWePlace(position,mid,m,n)==false){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return h;
    }
    
};