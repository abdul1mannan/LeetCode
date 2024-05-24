class Solution {
public:
    string reverseWords(string s) {
      int n=s.size();
        string temp="";
        string str="";
        int left=0;
        int right=n-1;
        while(left<=right){
            char ch=s[left];
            if(ch!=' '){
                temp+=ch;
               
            }
            else if(temp!=""&&ch==' '){
                if(str!=""){ str=temp+' '+str;}
                else str=temp;
                temp="";
            }
             left++;
        }
        if(temp!=""){
           if(str!="") str=temp+' '+str;
            else str=temp;
        }
     
        return str;
    }
};