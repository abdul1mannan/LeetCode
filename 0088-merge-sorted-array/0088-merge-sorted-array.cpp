class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=m-1;
        int b=n-1;
        int c=m+n-1;
        while(b>=0){
            if(a>=0&&nums1[a]>nums2[b]){
                nums1[c]=nums1[a];
                c--;
                a--;
            }
            else{
                nums1[c]=nums2[b];
                c--;
                b--;
            }
}
    }
    //   for(int i=0;i<n;i++){
    //       nums1[i+m]=nums2[i];
    //   }
    //      sort(nums1.begin(),nums1.end());
    // }
   
};