//                                     https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>>mpp;
        int n=cards.size();
        for(int i=0;i<n;i++){
            mpp[cards[i]].push_back(i);
        }
        int ans=1e8;
        for(int i=0;i<n;i++){
            for(auto idx:mpp[cards[i]]){
                if(abs(i-idx)>0){
                    ans=min(ans,abs(i-idx)+1);
                }
            }
        }
        if(ans==1e8)return -1;
        return ans;
    }
};
