class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int n=arr.size();
        int ans=1;
        for(int i=n-1;i>=0;i--){
            if(dp.find(arr[i]+difference)!=dp.end()){
                dp[arr[i]]=1+dp[arr[i]+difference];
                
            }
            else{
                dp[arr[i]]=1;
            }
            ans=max(ans,dp[arr[i]]);
        }
        return ans;

    }
};