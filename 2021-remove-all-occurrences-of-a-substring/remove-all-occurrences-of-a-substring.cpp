class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        string news=s;
        while(true){
            bool found=false;
            for(int i=0;i+m<=news.size();i++){
                if(news.substr(i,m)==part){
                    news=news.substr(0,i)+news.substr(i+m);
                   
                    found=true;
                    break;  
                }
            }
            if(!found){
                break;
            }
        }
        return news;
    }
};