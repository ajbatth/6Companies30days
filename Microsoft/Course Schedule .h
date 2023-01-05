class Solution {
private:
    bool dfs(vector<int>adj[],int node,vector<int>&vis,vector<int>&path_vis){
        vis[node]=1;
        path_vis[node]=1;

        for(auto n:adj[node]){
            if(path_vis[n]==1)return true;
            if(vis[n]==1)continue;
            
            if(dfs(adj,n,vis,path_vis)==true)return true;
        }

        path_vis[node]=0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>vis(n,0),path_vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,path_vis)==true)return false;
            }
        }
        return true;
    }
};
