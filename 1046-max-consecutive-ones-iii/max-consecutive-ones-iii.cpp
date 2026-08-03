class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        int zerocnt=k;
        int ans=0;
        while(r<n){
            if(zerocnt>=0){
                
                if(nums[r]==0){
                    zerocnt--;
                }
                r++;
            }
            // cout<<l<<" "<<r<<endl;
            while(zerocnt<0){
                
                if(nums[l]==0){
                    zerocnt++;
                }
                l++;
            }
            ans=max(ans,r-l);
            
            
            


        }
        return ans;
    }
};