class Solution {
public:
    string customSortString(string S, string T) {
        int a[26];
        for (int i=0; i<26; i++){
            a[i] = 0;
        }
        for (auto ch : T){
            a[ch-'a']++;
        }
        string res = "";
        for (auto ch : S){
            while (a[ch-'a'] > 0){
                string tmp(1,ch);
                res += tmp;
                a[ch-'a']--;
            }
        }
        for (int i=0; i<26; i++){
            while (a[i] > 0){
                string tmp(1,'a'+i);
                res += tmp;
                a[i]--;
            }
        }
        return res;
    }
};