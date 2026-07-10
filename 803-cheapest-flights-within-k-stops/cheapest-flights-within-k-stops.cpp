
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int, pair<int,int>>>pq;
        pq.push({0,{src,0}});
        // {stops, {node, cost}}
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!pq.empty()){
            auto [stop,r]=pq.front();
            pq.pop();
            auto [node,cost]=r;
            if(stop>k) continue;
            for(auto [adjnode,wt]:adj[node]){
                if(stop <= k && (dist[adjnode]>cost+wt)){
                    dist[adjnode]=cost+wt;
                    pq.push({stop + 1, {adjnode, cost + wt}});
                }
                
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};