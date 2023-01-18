//                         https://leetcode.com/problems/increasing-triplet-subsequence/description/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>lis;
        lis.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>lis.back()){
                lis.push_back(nums[i]);
                continue;
            }
            auto it=lower_bound(lis.begin(),lis.end(),nums[i]);
            lis[it-lis.begin()]=nums[i];
        }
        return lis.size()>=3;
    }
};
