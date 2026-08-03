class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int l=0,r=0;
        int n=s.size();
        int maxfreq=0,maxlen=0;
        while(r<n){
            freq[s[r]-'A']++;
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            if((r-l+1-maxfreq)<=k){
                maxlen=max(maxlen,r-l+1);
            }
            else{
                freq[s[l]-'A']--;
                l++;
            }
            r++;
            
        }
        return maxlen;
    }
};