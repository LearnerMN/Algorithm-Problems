#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


using namespace std;

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;

const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

vector<int> edges[100005];

int dp[100005][2];

int solve(int v, int p, int k) {
  if(dp[v][k] >= 0) return dp[v][k];
  int totalWays = 1;
  int allDiff = 1;
  int numChild = 0;
  for(int i = 0; i < edges[v].size(); i++) {
    int w = edges[v][i];
    if(w == p) continue;
    numChild++;
    totalWays = (int)((totalWays * (ll)(solve(w, v, 1) + solve(w, v, 0))) % MOD);
    allDiff = (int)((allDiff * (ll)(solve(w, v, 0))) % MOD);
  }
  if(numChild == 0 && k == 0) {
    dp[v][k] = 0;
  }
  else if(k == 0) {
    dp[v][k] = (totalWays - allDiff + MOD) % MOD;
  }
  else {
    dp[v][k] = totalWays;
  }
  return dp[v][k];
}

void solve() {
	freopen("input.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    edges[x].push_back(y);
    edges[y].push_back(x);
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  dp[n][0] = -1;
  dp[n][1] = -1;
  printf("%d\n", (2*solve(1, -1, 0)) % MOD);
}

int main() {
  solve();
  return 0;
}
/*

xyxxy
011


*/