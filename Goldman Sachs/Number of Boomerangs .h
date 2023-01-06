//                                     https://leetcode.com/problems/number-of-boomerangs/description/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int count=0;
        for(int i=0;i<n;i++){
            map<pair<int,int>,int>mpp;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                double x=points[i][0]-points[j][0];
                double y=points[i][1]-points[j][1];
                double dis=sqrt(x*x + y*y);
                int d=dis;
                double deci=dis-d;
                int dec=deci*1e6;
                mpp[{d,dec}]++;
            }
            for(auto x:mpp){
                int c=x.second;
                count+=c*(c-1);
            }

        }
        return count;
    }
};
