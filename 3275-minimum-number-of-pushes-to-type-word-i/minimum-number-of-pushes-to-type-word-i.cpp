class Solution {
public:
    int minimumPushes(string word) {
        int i=word.size();
        int cnt=0;
        if(i<=8){
            return i;
        }
        else if(i<=16){
            return (8+(i-8)*2);
        }
        else if(i>=16&&i<24){
            return (8*3+(i-16)*3);
        }
        else{
            return (8*6+(i-24)*4);
        }
    }
};