class Solution {
public:
    char findTheDifference(string s, string t) {
        int res_ch = s[0];
        for (int i=1; i<s.size(); i++){
            res_ch = res_ch ^ (int)s[i];
        }
        for (int i=0; i<t.size(); i++){
            res_ch = res_ch ^ (int)t[i];
        }
        return (char)res_ch;
    }
};