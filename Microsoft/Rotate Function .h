/*
Now, as per the question :

F(0) = (0 * a) + (1 * b) + (2 * c) + (3 * d) + (4 * e) = 0 + b + 2c + 3d + 4e
F(1) = (1 * a) + (2 * b) + (3 * c) + (4 * d) + (0 * e) = a + 2b + 3c + 4d + 0
F(2) = (2 * a) + (3 * b) + (4 * c) + (0 * d) + (1 * e) = 2a + 3b + 4c + 0 + e

Now subtracting 2 equations,

F(1) - F(0) = a + b + c + d - 4e = a + b + c + d + e - 5e
Therefore, F(1) = F(0) + a + b + c + d + e - 5e = F(0) + SUM - N*e

F(2) - F(1) = a + b + c + e - 4d = a + b + c + d + e - 5d
Therefore, F(2) = F(1) + a + b + c + d + e - 5d = F(1) + SUM - N*d
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxSum=INT_MIN;
        int n=nums.size();
        vector<int>dp(n,0);

        int sum=0;
        for(auto num:nums)sum+=num;

        for(int i=0;i<n;i++)dp[0]+=i*nums[i];
        maxSum=max(maxSum,dp[0]);
        
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+sum-n*nums[n-i];
            maxSum=max(maxSum,dp[i]);
        }
        return maxSum;
    }
};
