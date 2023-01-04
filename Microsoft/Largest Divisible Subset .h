class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++)hash[i]=i;
        int maxi=INT_MIN;
        int idx;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    idx=i;
                }
            }
        }
        vector<int>lds;
        lds.push_back(nums[idx]);
        while(hash[idx]!=idx){
            idx=hash[idx];
            lds.push_back(nums[idx]);
        }
        return lds;
        
    }
};
