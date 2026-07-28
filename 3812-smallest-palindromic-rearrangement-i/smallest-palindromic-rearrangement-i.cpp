class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n<=3){
            return s;
        }
        vector<int>alpha(26,0);
       
        for(int i=0;i<n;i++){
            alpha[s[i]-'a']++;
        }
        string ans="";
        int left=26;
        for(int i=0;i<26;i++){
            int freq=alpha[i]/2;
            if(alpha[i]%2==1){
                left=(i);
            }
            while(freq--){
                ans+=(i+'a');
            }
        }
        string str="";
        if(left!=26){
            ans+=(left+'a');
            for(int i=ans.size()-2;i>=0;i--){
                str+=ans[i];
            }
            ans=ans+str;
            return ans;
        }
        else{
            for(int i=ans.size()-1;i>=0;i--){
                str+=ans[i];
            }
            ans=ans+str;
            return ans;  

        }
        return ans;
        

        
    }
};