class Solution {
public:
    int subarray(vector<int>& nums, int k){
        int n=nums.size();
        int l=0,r=0;
        int cntodd=0;
        int ans=0;
        while(r<n){
            if(nums[r]%2){
                cntodd++;
            }
            while(cntodd>k){
                if(nums[l]%2){
                    cntodd--;
                }
                l++;
            }
            ans+=(r-l+1); 
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarray(nums,k)-subarray(nums,k-1);
    }
};