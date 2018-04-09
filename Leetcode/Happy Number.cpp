class Solution {
public:
    bool isHappy(int n) {
        int slow = n,fast = n;
        do {
            slow = getNewVal(slow);
            fast = getNewVal(fast);
            fast = getNewVal(fast);
        }while (slow != fast);
        return slow == 1 ? true : false;
    }
    
private:
    int getNewVal(int n){
        int sums = 0;
        while (n > 0){
            int v = n % 10;
            sums += v*v; 
            n /= 10;
        }
        return sums;
    }
};