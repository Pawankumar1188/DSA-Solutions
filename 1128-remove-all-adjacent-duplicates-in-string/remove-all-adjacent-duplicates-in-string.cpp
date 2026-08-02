class Solution {
public:
    string removeDuplicates(string s) {
        string resultstack="";
        for(char c:s){
            
            if(resultstack.size()==0){
                resultstack+=c;
            }
            else if(resultstack.back()==c){
                resultstack.erase(resultstack.size()-1);
            }
            else{
                resultstack+=c;
            }
        }
        return resultstack;
    }
};