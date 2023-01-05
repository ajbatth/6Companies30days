class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mpp;
        for(auto it:rectangles){
            int x1=it[0],y1=it[1],x2=it[2],y2=it[3];
            mpp[{x1,y1}]++;
            mpp[{x2,y2}]++;
            mpp[{x1,y2}]--;
            mpp[{x2,y1}]--;
        }
        int pos=0,neg=0;
        for(auto x:mpp){
            if(x.second==1)pos++;
            if(x.second==-1)neg++;
            if(x.second>1 || x.second<-1)return false;
        }
        if(pos==2 && neg==2)return true;
        return false;
    }
};
