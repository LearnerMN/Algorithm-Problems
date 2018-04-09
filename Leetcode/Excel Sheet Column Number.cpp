class Solution {
public:
    int titleToNumber(string s) {
        int sums = 0;
        for (int i=s.size()-1,t=0; i>=0; i--,t++){
            sums += ((int)s[i]-64)*pow(26,t);
        }
        return sums;
    }
};