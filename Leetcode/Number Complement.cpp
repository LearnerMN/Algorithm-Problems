class Solution {
public:
    int findComplement(int num) {
        if (num == 1) return 0;
        int m = INT_MAX;
        while (num & m) m <<= 1;
        
        return ~m & ~num;
    }
};