class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto [effort,pos]=pq.top();
            auto [i, j] = pos;
            if(i==n-1&&j==m-1){
                return effort;
            }
            pq.pop();
            for(auto [i_,j_]:dir){
                int ni=i+i_;
                int nj=j+j_;
                if(ni<0||ni>=heights.size()||nj<0||nj>=heights[0].size()){
                    continue;
                }
                
                int newEffort = max(effort, abs(heights[ni][nj] - heights[i][j]));
                if(newEffort<dist[ni][nj]){
                    dist[ni][nj]=newEffort;
                    pq.push({newEffort,{ni,nj}});
                }
                
            }
        }
        return dist[n-1][m-1];
    }
};