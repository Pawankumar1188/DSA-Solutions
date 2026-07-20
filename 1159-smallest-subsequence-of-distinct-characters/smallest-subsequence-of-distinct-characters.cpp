class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        unordered_map<char,int>index;
        unordered_map<char,int>vis;
        stack<char>stk;
        for(int i=0;i<n;i++){
            index[s[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(vis[s[i]]!=0){
                continue;
            }
            if(stk.empty()){
                stk.push(s[i]);
                vis[s[i]]=2;
            }
            while(!stk.empty() && stk.top()>s[i] && index[stk.top()]>i){
                vis[stk.top()]=0;
                stk.pop();
                
            }
            
            if(vis[s[i]]==0){
                stk.push(s[i]);
                vis[s[i]]=2;
            }
        }
        string ans="";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};