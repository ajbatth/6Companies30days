//                                     https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod=1e9+7;
        vector<long long>dp(n+1,0);
        long long people_with_secret=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(i-delay>0)people_with_secret=(people_with_secret+dp[i-delay])%mod;
            if(i-forget>0)people_with_secret=(people_with_secret-dp[i-forget]+mod)%mod;
            dp[i]=people_with_secret;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};
