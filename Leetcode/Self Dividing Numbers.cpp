class Solution {
public:
    bool isDivide(int n){
        int tmp = n;
        while (tmp > 0){
            int d = tmp%10;
            if (d == 0 || n % d != 0){
                return false;
            }
            tmp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for (int i=left; i<=right; i++){
            if (isDivide(i))
                v.push_back(i);
        }
        return v;
    }
};