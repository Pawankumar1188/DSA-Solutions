class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int cnt=0;
        int start=0;
        int end=0;
        while(end<s.size()){
            if(cnt==0){
                start=end;
            }
            if(s[end]=='('){
                cnt++;
                
            }
            else{
                cnt--;
                if(cnt==0){
                    str=str+s.substr(start+1,end-start-1);
                }
            }
            end++;
        }
        return str;
    }
};