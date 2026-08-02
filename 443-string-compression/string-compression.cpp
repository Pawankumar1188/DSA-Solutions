class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=1;
        int ans=0;
        vector<char>res;
        for(int i=0;i<chars.size()-1;i++){
            if(chars[i]==chars[i+1]){
                cnt++;
            }
            else{
                ans++;
                res.push_back(chars[i]);
                if(cnt>1){
                    string str=to_string(cnt);
                    ans+=str.size();
                    for(auto ch:str){
                        res.push_back(ch);
                    }
                }
                cnt=1;

            }
        }
        res.push_back(chars.back());
        if(cnt>1){
            string str=to_string(cnt);
            ans+=str.size();
            for(auto ch:str){
                res.push_back(ch);
            }
        }
        chars=res;
        return chars.size();
    }
};