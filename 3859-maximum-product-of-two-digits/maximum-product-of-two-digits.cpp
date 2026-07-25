class Solution {
public:
    int maxProduct(int n) {
        int f=INT_MIN;
        int s=INT_MIN;
        while(n>0){
            int d=n%10;
            n=n/10;
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
        return (f*s);
    }
};