class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map< char,int > mp;
        int result = 0;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (mp.find(ch) != mp.end()){
                result = max((int)mp.size(), result);
                int x = mp[ch];
                mp.clear();
                for (int k=x+1; k<i; k++){
                    mp[s[k]] = k;
                }
            }
            mp[ch] = i;
        }
        result = max((int)mp.size(), result);
        return result;
    }
};