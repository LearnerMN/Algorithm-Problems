class Solution {
    
public:
    
    int toInt(int i){
        if (1 == i || 0 == i || 8 == i)
            return i;
        if (2 == i) return 5;
        if (5 == i) return 2;
        if (6 == i) return 9;
        if (9 == i) return 6;
        return -1;
    }
    
    int toChange(int n){
        int t = 0;
        while (n > 0){
            int d = n%10;
            int l = toInt(d);
            n /= 10;
            t = t*10 + l;
            if (l == -1)
                break;
        }
        if (t > 0 && n != t) return t;
        return -1;
    }
    
    bool isCheck(int n){
        bool r = false;
        while (n > 0){
            int d = n%10;
            if (2 == d || 5 == d || d == 6 || d == 9){
                r = true;
            }
            if (d == 3 || d == 4 || d == 7)
                return false;
            n /= 10;
        }
        return r;
    }

    int rotatedDigits(int N) {
        int counter = 0;
        for (int i=1; i<=N; i++){
            if (isCheck(i)) counter++;
        }
        return counter;
    }
};