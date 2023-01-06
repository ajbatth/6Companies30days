
class Solution {
public:
    string longestPrefix(string s) {
        long long mod=1e9+7;
        long long  pph=0,psh=0,n=s.length(),pow=1,maxi=-1;
        for(long long  i=0;i<n-1;i++){
            pph=((pph*29)%mod+(s[i]-'a'+1))%mod;
            psh=(psh+((s[n-i-1]-'a'+1)*pow)%mod)%mod;
            pow=(pow*29)%mod;
            if(pph==psh){
                maxi=max(maxi,i);
                //cout<<i<<" "<<maxi<<endl;
            }
        }
        if(maxi==-1)return "";
        return s.substr(0,maxi+1);
    }
};
