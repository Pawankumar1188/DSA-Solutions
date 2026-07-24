class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool>prexor(2048,false);
        vector<bool> ans(2048, false);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                prexor[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<2048;i++){
            if(prexor[i]==false) continue;
            for(int j=0;j<n;j++){
                ans[i^nums[j]]=true;
            }
        }
        int cnt=0;
        for(auto c:ans){
            if(c){
                cnt++;
            }
        }
        return cnt;
    }
};