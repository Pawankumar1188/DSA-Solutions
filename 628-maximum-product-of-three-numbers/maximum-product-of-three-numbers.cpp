class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int f=INT_MIN;
        int s=INT_MIN;
        int t=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int d=nums[i];
            if(d>f){
                t=s;
                s=f;
                f=d;
            }
            else if(d==f){
                t=s;
                s=d;
            }
            else if(s<d){
                t=s;
                s=d;
            }
            else if(s==d){
                t=s;
            }
            else if(t<d){
                t=d;
            }
        }
        int fm=INT_MAX;
        int sm=INT_MAX;
        for(int i=0;i<n;i++){
            int d=nums[i];
            if(d<fm){
                sm=fm;
                fm=d;
            }
            else if(d==fm){
                sm=d;
            }
            else if(sm>d){
                sm=d;
            }
            
        }

        int a=(f*s*t);
        int b=(fm*sm*f);
        
        return max(a,b);
    }
};