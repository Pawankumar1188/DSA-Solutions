class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        //odd len
        for(int i=0;i<n;i++){
            string curr="";
            int l=i-1;
            int r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
            }
            curr=s.substr(l+1,r-l-1);
            if(curr.size()>ans.size()){
                ans=curr;
            }
            
        }
        for(int i=0;i<n;i++){
            string curr="";
            int l=i;
            int r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
            }
            curr=s.substr(l+1,r-l-1);
            if(curr.size()>ans.size()){
                ans=curr;
            }
            
        }
        return ans;

    }
};