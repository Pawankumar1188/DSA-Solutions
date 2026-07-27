class Solution {
public:
    bool isleap(int year){
        return (year%400==0 ||(year%4==0&&year%100!=0));
    }
    int datefromstart(string date){
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));

        vector<int>mon={31,28,31,30,31,30,31,31,30,31,30,31};
        int days=0;
        for(int i=1971;i<year;i++){
            days+=isleap(i)?366:365;
        }
        for(int m=1;m<month;m++){
            days+=mon[m-1];
            if(m==2&&isleap(year)){
                days++;
            }
        }
        days+=day;
        return days;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(datefromstart(date1)-datefromstart(date2));
    }
};