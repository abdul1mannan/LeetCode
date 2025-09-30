// Last updated: 10/1/2025, 12:47:11 AM
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>popl;
        for(auto &it:logs){
            ++popl[it[0]];
            --popl[it[1]];
        }
        int maxi=0;
        int year;
        int count=0;
        
        for(auto &i:popl){
            count+=i.second;
            if(count>maxi){
                maxi=count;
                year=i.first;
            }
        }
        return year;
    }
};