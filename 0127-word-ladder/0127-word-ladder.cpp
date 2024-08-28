class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int count=0;
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        if(st.find(endWord)==st.end()){
            return 0;
        }
        
        while(!q.empty()){
            string s=q.front().first;
            int step=q.front().second;
            q.pop();
            if(s==endWord){
                return step;
            }
            for(int i=0;i<s.size();i++){
                char orig=s[i];
                
                for(char j='a';j<='z';j++){
                    s[i]=j;
                    if(st.find(s)!=st.end()){
                        q.push({s,step+1});
                        st.erase(s);
                    }
                    

                }
                s[i]=orig;
            }
        }
        return 0;
    }
};