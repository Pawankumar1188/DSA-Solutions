class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currsum=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(currsum>=0){
                currsum+=nums[i];

            }
            else{
                currsum=max(currsum,nums[i]);
            }
            ans=max(ans,currsum);
            
        }
        return ans;
    }
};