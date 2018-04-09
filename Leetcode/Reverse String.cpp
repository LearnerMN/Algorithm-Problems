#include <vector>
class Solution {
public:
    string reverseString(string str) {
        vector< char > data(str.begin(), str.end());
        reverse(data.begin(),data.end());
        string res( data.begin(), data.end() );
        return res;
    }
};