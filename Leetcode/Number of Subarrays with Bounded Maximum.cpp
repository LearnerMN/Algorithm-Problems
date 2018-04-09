class Solution {
    
public:
    int sumOfsub(int n){
        return (n * (n + 1)) / 2;
    }
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result = 0;
        int counter1 = 0;
        int counter2 = 0;
        for (int i=0; i<A.size(); i++){
            if (A[i] > R){
                result += sumOfsub(counter1) - sumOfsub(counter2);
                counter1 = 0, counter2 = 0;
            }else if (A[i] < L){
                counter1++;
                counter2++;
            }else{
                result -= sumOfsub(counter2);
                counter2 = 0;
                counter1++;
            }
        }
        result += sumOfsub(counter1) - sumOfsub(counter2);
        return result;
    }
};