class Solution {
private:
    void comb(int k,int n, int i,int sum,vector<int>&v,vector<vector<int>>&ans){
        if(i>10)return;
        if(v.size()==k){
            if(sum==n)
            ans.push_back(v);
            return;
        }
        if(sum>=n){
            if(v.size()==k && sum==n)ans.push_back(v);
            return;
        }
        comb(k,n,i+1,sum,v,ans);
        if(i+sum<=n){
            v.push_back(i);
            comb(k,n,i+1,sum+i,v,ans);
            v.pop_back();
        }
        else return;

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        vector<vector<int>>ans;
        comb(k,n,1,0,v,ans);
        return ans;
        
    }
};
