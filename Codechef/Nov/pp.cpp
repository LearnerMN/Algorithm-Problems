#include <iostream>
#include <vector>
using namespace std;

int func(int L, int N, int K);

// To execute C++, please define "int main()"
int main() {
  cout<<func(3, 3, 1)<<endl;
  return 0;
}

int func(int L, int N, int K) {
  
  // some code
  vector< vector< long > > dp(L+1, vector<long>(N+1, 0)); // initial value 0;
  dp[0][0] = 1;
  long MOD = 1000000007;
  for (int i=1; i<=L; i++){
    for (int j=1;j<=N; j++) {
        int X = dp[i-1][j-1] * (N-j+1);
        int Y = dp[i-1][j] * max(j-K+1, 0);
        cout<<i<<" "<<j<<" - "<<X<<" "<<Y<<endl;
        dp[i][j] = X + Y;
        dp[i][j] %= MOD;
    }
  }
  return (int) dp[L][N];
} 


/* 
Your tv channel contains N different titles of movies and you wants to watch to L (not necessarily different) movies during your holiday .  You create a playlist so that:

Every movie is played at least once
A movie can only be played again only if K other movie have been played
Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.

Eg.
Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlist. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].


N = 2, L = 3, K = 1
Output:

  1, 2
  1, 2, 1 <-- permutation of this
  2, 1
  2, 2


Input: N = 2, L = 3, K = 1
Output: 2
 

dp[i][j]  means the total numeber of playlists of length i having j unique movies
so now you have N different movei titles but you only want L movies and repeat only after k "other" movies

result == dp[L][N] => total number of playlists of length L having N unique movies


fuction (N, L, K) {
  // algo
  
  return dp[L][N]
}


dp[i][j] == at the last movie

you have played this movie earlier = X
you have not played this movie earlier = Y
 
dp[i][j] = X + Y

1.......,j<<--
1....j-1,

X = dp[i-1][j-1] * (N-j)
total of N movies out of which you choosen j movies 
-- so remaining is N-j ways of choosing dp[i-1][j-1]

Y = the case you have not played this movie

// there must be i-1 lenght playlist and you are adding one new movie i.e current move
 
dp[i-1][j] * max(j-K, 0) -- choosing j movies and discarding the last K

number of ways of choosing??
max(j-K, 0)




 
// for i : 0->L:
  N, N-K

Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
1
 


 */