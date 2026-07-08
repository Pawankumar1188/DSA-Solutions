class Solution {
public:
    int ans=INT_MAX;
    void bfs(string bw, string ew,unordered_map<string,int>&mp){
        queue<string>q;
        q.push(bw);
        int cnt=0;
        while(!q.empty()){
            
            int sz=q.size();           
            for(int s=0;s<sz;s++){
                string word=q.front();
                q.pop();
                for(int i=0;i<word.size();i++){
                    string currw=word;
                    for(int j=0;j<26;j++){
                        currw[i]=char('a'+j);
                        if(mp[currw]==2){
                            q.push(currw);
                            mp[currw]=1;
                            if(currw==ew){
                                ans=cnt+1;
                                return;
                            }

                        }
                    }
                }

            }
            cnt++;
            cout<<cnt<<" "<<q.size()<<endl;
        }
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            mp[wordList[i]]=2;
        }

        bfs(beginWord,endWord,mp);
        if(ans==INT_MAX){
            return 0;
        }
        return ans+1;



    }
};