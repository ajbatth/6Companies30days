//                                          https://leetcode.com/problems/maximum-good-people-based-on-statements/description/

class Solution {
private:
    int count_good(vector<vector<int>>&v,vector<int>&bit){
        int n=v.size();
        int count=0;
        bool flag=1;
        for(int i=0;i<n;i++){
            if(bit[i]==1){
                count++;
                for(int j=0;j<n;j++){
                    if((v[i][j]==1 && bit[j]==0)||(v[i][j]==0 && bit[j]==1))flag=0;
                }
            }
        }
        if(flag)return count;
        return 0;
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int N=pow(2,n);
        int maxi=INT_MIN;
        for(int i=0;i<N;i++){
            int num=i;
            vector<int>bit(n,0);
            int j=0;
            while(num>=1){
                bit[j]=num%2;
                num/=2;
                j++;
            }
            maxi=max(maxi,count_good(statements,bit));

        }
        return maxi;
        
    }
};
