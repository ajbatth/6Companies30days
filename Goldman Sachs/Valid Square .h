//                       https://leetcode.com/problems/valid-square/description/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int,int>>v;
        v.push_back({p1[0],p1[1]});
        v.push_back({p2[0],p2[1]});
        v.push_back({p3[0],p3[1]});
        v.push_back({p4[0],p4[1]});
        for(int i=0;i<4;i++){
            vector<double>dis;
            for(int j=0;j<4;j++){
                if(i==j)continue;
                double x=v[i].first-v[j].first;
                double y=v[i].second-v[j].second;
                double d=sqrt(x*x + y*y);
                dis.push_back(d);
            }
            sort(dis.begin(),dis.end());
            if(abs(dis[0]-dis[1])>0.000001 || dis[2]<=dis[1])return 0;
            double side=sqrt(2.0)*dis[0];
            //for(auto x:dis)cout<<x<<" ";
            //cout<<abs(side-dis[0])<<" ";
            if(abs(side-dis[2])>0.000001)return 0;
            //cout<<side<<endl;
        }
        return 1;
    }
};
