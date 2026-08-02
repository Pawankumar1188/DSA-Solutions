class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        
        int i=0;
        int j=n-1;
        string ans="";
        while(s[i]==' '){
            i++;
        }
        while(s[j]==' '){
            j--;
        }
        int l=j;
        int r=j;
        while(l>=i){
            if(s[l]==' '&&r==l){
                l--;
                r--;
            }
            else if(s[l]==' '&&r-l>=1){
                ans=ans+s.substr(l+1,r-l)+' ';
                l--;
                r=l;
            }
            else{
                l--;
            }
            
            
        }
        if(r-l>0){
            ans=ans+s.substr(l+1,r-l);
        }
        return ans;

    }
};