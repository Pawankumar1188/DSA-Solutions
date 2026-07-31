class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[word[i]-'a']++;
        }
        int cnt=0;
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<26;i++){
            if(i<8){
                cnt+=v[i];
            }
            else if(i>=8&&i<16){
                cnt=cnt+2*v[i];
            }
            else if(i>=16&&i<24){
                cnt=cnt+3*v[i];
            }
            else{
                cnt=cnt+4*v[i];
            }
        }
        return cnt;
    }
};