// Last updated: 10/1/2025, 12:47:33 AM
class Solution {
public:
    string removeDuplicates(string s) {
          int i=1;
   while(i<2 && i<s.length()){


     if(s[i]==s[i-1]){
          i++;
     s.erase(i-2,2);
     i=i-1;}
      else if ( s[i]==s[i+1])
      {
               i++;
     s.erase(i-1,2);
     i=i-1;}
      
      else i++;
   }


   while(i<s.length()){
     if(s[i]==s[i+1]){
         i++;
     s.erase(i-1,2);
     
     i=i-2;}
      else i++;
   }
  

   return s;
    }
};