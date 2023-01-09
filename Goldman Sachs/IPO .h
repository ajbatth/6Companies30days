//                  https://leetcode.com/problems/ipo/description/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        int n=profits.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int i=0;
        while(k>0 && i<n && v[i].first<=w){
           while(i<n && v[i].first<=w){
               pq.push(v[i].second);
               i++;
           }
           w+=pq.top();
           pq.pop();
           k--;
        }
        while(k-- && !pq.empty()){
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};
