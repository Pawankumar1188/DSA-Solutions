class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp['a']>=1&&mp['b']>=1&&mp['c']>=1){
                ans+=(n-r);
                
                mp[s[l]]--;
                l++;
                // cout<<r<<" "<<ans<<endl;
            }
            r++;
            

        }
        // while(l<n){
            
            
        //     if(mp['a']>=1&&mp['b']>=1&&mp['c']>=1){
        //         ans++;
                
                
                
        //     }
        //     mp[s[l]]--;
        //     l++;


        // }

        // // // cout<<l<<endl;
        // // ans+=(n-2-l);
        
        

        return ans;
    }
};