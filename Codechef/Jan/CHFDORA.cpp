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

bool checker(int l, int r, int t, int b, int n, int m){
	return 0 <= l && r < m && 0 <= t && b < n;
}
int main(){
	freopen("input.txt", "r", stdin);
	int t, n, m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		vector<vector<int>> v(n, vector<int>(m, 0));
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cin>>v[i][j];
			}
		}
		int counter = 0;
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				int l = j, r = j;
				int t = i, b = i;
				while (checker(l, r, t, b, n, m) && v[i][l] == v[i][r] && v[t][j] == v[b][j]){
					counter++;
					l--; r++; t--; b++;
				}
			}
		}
		cout<<counter<<endl;
	}
 return 0;
}
