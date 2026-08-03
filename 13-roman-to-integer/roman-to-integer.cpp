class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mp;
        mp["I"] = 1;
        mp["V"] = 5;
        mp["IV"] = 4;
        mp["X"] = 10;
        mp["IX"] = 9;
        mp["L"] = 50;
        mp["XL"] = 40;
        mp["C"] = 100;
        mp["XC"] = 90;
        mp["D"] = 500;
        mp["CD"] = 400;
        mp["M"] = 1000;
        mp["CM"] = 900;
        int ans=0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp.count(s.substr(i, 2)) != 0) {
                ans += mp[s.substr(i, 2)];
                i++;
            }
            else if (mp.count(s.substr(i, 1))) {
                ans += mp[s.substr(i, 1)];
            } 
        }
        return ans;
    }
};