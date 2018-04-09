class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set< int > s(J.begin(),J.end());
        int c = 0;
        for (auto ch : S){
            if (s.find(ch) != s.end())
                c++;
        }
        return c;
    }
};