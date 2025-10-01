class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        
       
        int n = arrivals.size();
         queue<pair<int,int>>kept;
        map<int, int> mpp;
        int cnt = 0;
     
        for (int i = 0; i < n; i++) {
            int start=i-w+1;
            while(!kept.empty() && kept.front().first < start){
                int type=kept.front().second;
                kept.pop();
                if(--mpp[type]==0) mpp.erase(type);
            }
            int item=arrivals[i];

            if (mpp[arrivals[i]] >= m) {
                cnt++;
        
            }
            else {
                kept.push({i,item});
                mpp[item]++;
            }
        }
        return cnt;
    }
};