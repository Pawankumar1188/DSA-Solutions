class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1){
            return intervals;
        }
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<n-1;i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            cout<<i<<endl;
            while(i+1<n && e>=intervals[i+1][0]){
                e=max(intervals[i+1][1],e);
                i++;
            }
            ans.push_back({s,e});
        }

        if(ans[ans.size()-1][1]>=intervals[n-1][0]){
            ans[ans.size()-1][1]=max(intervals[n-1][1],ans[ans.size()-1][1]);
        }
        else{
            ans.push_back(intervals[n-1]);
        }
        return ans;
    }
};