class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n>=3){
            
            for(int i=1;i<n;i++){
                if((1<<i)>n){
                    return (1<<i);
                    break;
                }
            }

            
        }
        return n;
    }
};