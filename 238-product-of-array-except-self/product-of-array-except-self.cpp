class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>output=nums;
        //suffix
        for(int i=n-2;i>=0;i--){
            output[i]*=output[i+1];
        }
        for(int i=1;i<nums.size();i++){
            nums[i]*=nums[i-1];
        }
        
        output[0]=output[1];
        for(int i=1;i<n-1;i++){
            output[i]=output[i+1]*nums[i-1];
        }
        output[n-1]=nums[n-2];
        return output;
    }
};