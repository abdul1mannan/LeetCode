class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        
        vector<long long>ps(n);

        ps[0]=skill[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+skill[i];
        }

        long long total=0;
        for(int j=0;j<m-1;j++){
            long long gap=LLONG_MIN;
            long long prevsum=0;

            for(int i=0;i<n;i++){
                long long currentgap=ps[i]*mana[j]-prevsum*mana[j+1];
                gap=max(gap,currentgap);
                prevsum=ps[i];
            }

            total+=gap;
        }
        long long ans=total+ps[n-1]*mana[m-1];
        return ans;

    }
};