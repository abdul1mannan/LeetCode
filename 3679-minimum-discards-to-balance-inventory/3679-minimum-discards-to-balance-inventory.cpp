class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        
       
        int n = arrivals.size();
        map<int, int> mpp;
        int cnt = 0;
        for (int i = 0; i < w; i++) {
            mpp[arrivals[i]]++;
            if (mpp[arrivals[i]] > m) {
                cnt++;
               mpp[arrivals[i]]--;
               arrivals[i]=0;
            }
        }
        int left = 0;
        for (int i = w; i < n; i++) {
            mpp[arrivals[left]]--;
            left++;
            mpp[arrivals[i]]++;
            if (mpp[arrivals[i]] > m) {
                cnt++;
               mpp[arrivals[i]]--;
               arrivals[i]=0;
            }
        }
        return cnt;
    }
};