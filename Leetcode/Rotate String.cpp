class Solution {
public:
    bool rotateString(string A, string B) {
        string tmp = A + A;
        return tmp.find(B) != string::npos;
    }
};