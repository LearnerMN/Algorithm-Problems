
class Solution {
public:
    int kthGrammar(int N, int K) {
        int c = 1<<N;
        int t = 0;
        while (K > 1){
            while (c/2 >= K){
                c /= 2;
            }
            c /= 2;
            t++;
            K -= c;
        }
        return t%2;
    }
};