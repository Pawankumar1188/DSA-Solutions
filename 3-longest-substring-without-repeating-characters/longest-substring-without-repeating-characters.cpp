class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        unordered_map<char,int>mp;
        int ans=0;
        while(r<n){
            while(mp[s[r]]>=1){
               
                mp[s[l]]--;
                l++;
                
            }
           
            mp[s[r]]++;
            r++;
        
            ans=max(ans,r-l);
        }
        return ans;
    }
};