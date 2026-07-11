class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<pair<long long,long long>>dist(n,{LLONG_MAX,0});
        priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;
        dist[0]={0,1};
        pq.push({0,0});
        while(!pq.empty()){
            auto [cost,node]=pq.top();
            pq.pop();
            if(cost>dist[node].first){
                continue;
            }
            for(auto [adjnode,w]:adj[node]){
                if(dist[adjnode].first>w+dist[node].first){
                    dist[adjnode].first=w+dist[node].first;
                    dist[adjnode].second=dist[node].second;
                    pq.push({dist[adjnode].first,adjnode});
                }
                else if(dist[adjnode].first==w+dist[node].first){
                    dist[adjnode].second=(dist[adjnode].second+dist[node].second)%mod;
                    
                }
                
            }
        }
        
        return dist[n-1].second;


    }
};