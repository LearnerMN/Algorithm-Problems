#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <set>

using namespace std;

int getMinSquares(int n){ 
    int* dp = new int[n + 1]; 
    dp[0] = 0; 
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 3; 

    for (int i = 4; i <= n; i++) { 
        dp[i] = i; 
        for (int x = 1; x <= 9; x++) { 
            int temp = x * x; 
            if (temp > i) 
                break; 
            else
                dp[i] = min(dp[i], 1 + dp[i - temp]); 
        } 
        cout<<i<<" "<<dp[i]<<endl;
    } 
  
    int res = dp[n]; 
    delete[] dp; 
  
    return res; 
} 

int main(){
	freopen("input.txt", "r", stdin);	
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		getMinSquares(n);
	}
 return 0;
}
