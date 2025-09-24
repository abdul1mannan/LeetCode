class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0) {
            return "0";
        }
        string res;
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);
        long long digit = num/den;
        res+=to_string(digit);
        long long rem=num%den;
        if(rem==0){
            return res;
        }
       res+=".";
       unordered_map<long long, int> hash;
        while(rem!=0){
           if(hash.count(rem)){
              int pos=hash[rem];
              res.insert(pos,"(");
              res+=')';
              break;
           }

           hash[rem]=(int)res.size();
           rem*=10;
           long long digit=rem/den;
           res+=to_string(digit);
           rem=rem%den;
        }
        return res;        
    }
};
