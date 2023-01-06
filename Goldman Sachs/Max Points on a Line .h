class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            map<pair<int,int>,int>mpp;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int x=(points[i][0]-points[j][0]);
                    int y=(points[i][1]-points[j][1]);
                    int g=__gcd(x,y);
                    x/=g;
                    y/=g;
                    mpp[{x,y}]++;
                }
            }
            int count=1;
            for(auto x:mpp){
                count=max(count,1+x.second);
            }
            ans=max(ans,count);
        }
        
        return ans;

    }
};
