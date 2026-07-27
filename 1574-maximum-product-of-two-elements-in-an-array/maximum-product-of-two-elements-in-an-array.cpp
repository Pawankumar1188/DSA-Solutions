class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int f=INT_MIN;
        int s=INT_MIN;
        for(int i=0;i<n;i++){
            int d=nums[i];
            if(d>f){
                s=f;
                f=d;
            }
            else if(d==f){
                s=d;
            }
            else if(s<d){
                s=d;
            }

        }
        return ((f-1)*(s-1));

    }
};