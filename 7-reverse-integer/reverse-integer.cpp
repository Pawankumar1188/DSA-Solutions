class Solution {
public:
    int reverse(int x) {
        long long num=x;
        int p=1;
        if(num<0){
            p=-1;
            num=num*-1;
        }
        long long revx=0;
        while(num>0){
            revx=revx*10;
            int r=(num%10);
            revx+=r;
            num=num/10;
        }
        if(revx>INT_MAX||revx<INT_MIN){
            return 0;
        }
        return p*(int)revx;
    }
};