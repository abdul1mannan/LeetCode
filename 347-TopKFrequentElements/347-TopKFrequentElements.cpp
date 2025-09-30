// Last updated: 10/1/2025, 12:48:47 AM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, pair<int, int>> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].first++;
            m[nums[i]].second=nums[i];
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
for (auto it = m.begin(); it != m.end(); it++) {
    p.push({it->second.first, it->second.second});
    
    if (p.size() > k) {
        p.pop();
    }
}
        
        vector<int>ans;
     while (!p.empty()) {
    auto topElement = p.top();
    ans.push_back(topElement.second);
    p.pop();
}
        return ans;
    }
};