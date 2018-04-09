class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int i = 0;
        while (num > 0){
            if (num % 2 == 0){
                res += pow(2,i);
            }
            
            num = num >> 1;
            
            i++;
        }
        return res;
    }
};