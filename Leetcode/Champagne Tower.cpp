class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101];
        for (int i=0; i<101; i++)
    	    for (int j=0; j<101; j++)
    		    dp[i][j] = 0;
        dp[0][0] = poured;
        for (int i=0; i<=query_row; i++){
            for (int j=0; j<=i; j++){
                if (dp[i][j] > 1){
                    double tmp = (dp[i][j]-1) / 2;
                    dp[i+1][j] += tmp;
                    dp[i+1][j+1] += tmp;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};