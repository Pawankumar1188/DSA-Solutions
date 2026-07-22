class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int>len;
        int cntone=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            if(s[i]=='0'){
                while(i<n&&s[i]=='0'){
                    cnt++;
                    i++;
                }
                len.push_back(cnt);
                i--;
            }
            else if(s[i]=='1'){
                
                while(i<n&&s[i]=='1'){
                    cnt++;
                    cntone++;
                    i++;
                }
                len.push_back(cnt);
                i--;
            } 
        }
        
        int newone=0;
        int m=len.size();
        if(s[0]=='0'){
            for(int i=0;i<m;i=i+2){
                if(i+2<m){
                    newone=max(newone,len[i]+len[i+2]);
                    
                }
            }
        }
        else{
            for(int i=1;i<m;i=i+2){
                if(i+2<m){
                    newone=max(newone,len[i]+len[i+2]);
                }
            }
        }
        
        return cntone+newone;        
    }
};