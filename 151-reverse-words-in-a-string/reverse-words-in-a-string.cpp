class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        int i = 0, j = n - 1;

        while (i < n && s[i] == ' ')
            i++;

        while (j >= 0 && s[j] == ' ')
            j--;

        string ans = "";

        int r = j;
        int l = j;

        while (l >= i) {

            // Skip consecutive spaces
            while (l >= i && s[l] == ' ')
                l--;

            if (l < i)
                break;

            r = l;

            // Find beginning of current word
            while (l >= i && s[l] != ' ')
                l--;

            ans += s.substr(l + 1, r - l);

            if (l >= i)
                ans += ' ';
        }

        return ans;
    }
};