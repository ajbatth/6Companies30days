class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int mini=INT_MAX,maxi=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(v[i]!=nums[i]){
                mini=min(mini,i);
                maxi=max(maxi,i);
            }
        }
        if(maxi==INT_MIN || mini==INT_MAX)return 0;
        return maxi-mini+1;
    }
};
