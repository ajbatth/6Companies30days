                                  https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/

class Solution {
private:
    int maxi=INT_MIN;
    vector<int>ans;
    void fxn(vector<int>&alice,int num,int i,vector<int>&bob){
        if(i>11){
            int sum=0;
            for(int i=0;i<bob.size();i++){
                if(bob[i]>0){
                    sum+=i;
                }
            }
            if(sum>maxi){
                maxi=sum;
                int temp=bob[0];                
                bob[0]+=num;
                ans=bob;
                bob[0]=temp;
            }
            return;
        }
        if(num>alice[i]){
            bob.push_back(alice[i]+1);
            fxn(alice,num-bob.back(),i+1,bob);
            bob.pop_back();
        }
        bob.push_back(0);
        fxn(alice,num,i+1,bob);
        bob.pop_back();
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>v;
        fxn(aliceArrows,numArrows,0,v);
        return ans;
    }
};
