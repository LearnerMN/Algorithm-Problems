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
int main(){
    int n = 2;
    int K = 25;
    // cin>>n;
    vector< int > v = { 3, 5, 2, 2 }; //(n);
    // for (int i=0; i<n; i++){
    //     cin>>v[i];
    // }
    vector< vector< int > > dp(n+1, vector< int >(K, 0));
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=K-1; j++){
            int x = 0;
            if (j - v[i-1] >= 0){
                x = max(dp[i-1][j - v[i-1]], (int)(dp[i][j - v[i-1]] != 0));
            }
            int val = dp[i-1][j] + (j % v[i-1] == 0)*i;
            dp[i][j] = max(x, val);
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=K-1; j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    int q = 1, k;
    // cin>>q;
    while (q--){
        k = 16;
        // cin>>k;
        int m = 0;
        
        cout<<dp[n][k]<<endl;
    }
 return 0;
}