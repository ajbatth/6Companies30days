//                                   https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<long long,long long>mpp;
        int mod=1e9+7;
        for(int num:nums){
            string s=to_string(num);
            reverse(s.begin(),s.end());
            mpp[num-stoi(s)]++;           
        }
        long long int count=0;
        for(auto x:mpp){
            count=(count+(x.second*(x.second-1))/2)%mod;
        }
        return count;
        

    }
};
