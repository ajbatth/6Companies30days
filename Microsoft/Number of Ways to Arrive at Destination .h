class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long>count(n,0),dis(n,1e18);
        dis[0]=0;
        count[0]=1;
        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,0});
        while(!q.empty()){
            int node=q.top().second;
            long long d=q.top().first;
            q.pop();
            for(auto n:adj[node]){
                if(d+n.second==dis[n.first]){
                    count[n.first]=(count[n.first]+count[node])%mod;
                }
                else if(d+n.second<dis[n.first]){
                    dis[n.first]=d+n.second;
                    count[n.first]=count[node];
                    q.push({dis[n.first],n.first});
                }
            }
        }
        return count[n-1];
    }
};
