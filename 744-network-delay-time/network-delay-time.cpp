class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [c,node]=pq.top();
            pq.pop();
            for(auto [adjnode,cost]:adj[node]){
                if(dist[adjnode]>cost+dist[node]){
                    dist[adjnode]=cost+dist[node];
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};