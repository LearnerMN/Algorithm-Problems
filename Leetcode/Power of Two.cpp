class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        long long f = 1;
        while (f != n){
            if (f > n){
                return false;
            }
            f <<= 1;
            cout<<f<<endl;
        }
        return true;
    }
};