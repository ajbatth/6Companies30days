//                                             https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(long numerator, long d) {
        if(numerator==0 || d==1)return to_string(numerator);
        string s="";
        if(numerator<0 ^ d<0)s+="-";
        numerator=abs(numerator);
        d=abs(d);
        s+=to_string(numerator/d);
        long long n=numerator%d;
        if(n==0)return s;
        s.push_back('.');
        map<long long,long long>rem;
        string r;
        while(n>0){
            if(rem.find(n)!=rem.end()){
                r.insert(rem[n],"(");
                r.push_back(')');
                break;
            }
            rem[n]=r.size();
            n*=10;
            r.push_back('0'+(n/d));
            n%=d;
        }
        return s+r;
        

    }
};
