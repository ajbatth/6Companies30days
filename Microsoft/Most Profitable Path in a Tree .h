class Solution {
private:
    int maxi=INT_MIN;
    void dfs1(vector<int>adj[],int root,int par,vector<int>&parent){
        parent[root]=par;
        for(auto child:adj[root]){
            if(child!=par){
                dfs1(adj,child,root,parent);
            }
        }
    }
    void dfs2(vector<int>adj[],int root,int par,vector<int>&dis_bob,vector<int>&amount,int dis,int sum){
        if(dis<dis_bob[root])sum+=amount[root];
        else if(dis==dis_bob[root])sum+=amount[root]/2;
        if(adj[root].size()==1 && adj[root][0]==par){
            maxi=max(maxi,sum);
        }
        for(auto child:adj[root]){
            if(child!=par){
                dfs2(adj,child,root,dis_bob,amount,dis+1,sum);
            }
        }

    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int>adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>parent(n);
        dfs1(adj,0,-1,parent);
        vector<int>dis_bob(n,1e8);
        int count=0,root=bob;
        while(root!=-1){
            dis_bob[root]=count;
            count++;
            root=parent[root];
        }
         dfs2(adj,0,-1,dis_bob,amount,0,0);
         return maxi;

    }
};
