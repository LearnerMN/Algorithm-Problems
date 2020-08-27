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

void printAnswer(vector<int> &ans, int x){
	cout<<x<<endl;
	for (int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;	
}
int main(){
	freopen("input.txt", "r", stdin);
	// freopen("marm_02.txt", "w", stdout);
	int t;
	cin>>t;
	while (t--){
		int n, m, a, b;
		cin>>n>>m;
		vector<vector<int>> v(n);
		vector<int> ans(n, 1);
		for (int i=0; i<m; i++){
			cin>>a>>b;
			--a, --b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		if (m % 2 == 0){
			printAnswer(ans, 1);
			continue;
		}

		bool foundOdd = false;
		for (int i=0; i<n; i++){
			if (v[i].size() & 1){
				foundOdd = true;
				ans[i] = 2;
				printAnswer(ans, 2);
				break;
			}
		}
		if (foundOdd){
			continue;
		}
		ans[a] = 2;
		ans[b] = 3;
		printAnswer(ans, 3);
	}
 return 0;
}

/*

1
5 5
1 2
1 3
2 3
2 4
3 4

3
5 5
1 2
1 3
2 3
2 4
3 4
5 3
1 2
2 3
3 4
5 5
1 2
2 3
3 4
4 5
5 1

*/