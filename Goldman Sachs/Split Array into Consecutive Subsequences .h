//                          https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>remain;
        for(auto x:nums) remain[x]++;
        int n=nums.size();
        unordered_map<int,int>end;
        for(int i=0;i<n;i++){
            if(remain[nums[i]]==0)continue;
            remain[nums[i]]--;
            if(end[nums[i]-1]>0){
                end[nums[i]-1]--;
                end[nums[i]]++;
            }
            else if(remain[nums[i]+1]>0 && remain[nums[i]+2]>0){
                remain[nums[i]+1]--;
                remain[nums[i]+2]--;
                end[nums[i]+2]++;
            }
            else return 0;
        }
        return 1;
    }
};

/*1 2 3 3 4 4 5
  1 2 3 4 
  3 4 5
  
  
  4 2


*/
