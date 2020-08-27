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
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n, m, a;
		cin>>n>>m;
		vector< pair<int,int> > v;
		for (int i=0; i<n; i++){
			cin>>a;
			v.push_back(make_pair(a, i%m));
		}
		sort(v.begin(), v.end());
		int minDiff = INT_MAX;
		map< int, int > mp;
		mp[v.front().second]++;
		int start = 0;
		for (int i=1; i<n; i++){
			mp[v[i].second]++;
			if (mp.size() < m) continue;
			while (mp[v[start].second] > 1){

				mp[v[start].second]--;
				start++;
			}
			
			cout<<v[start].second<<"-"<<v[start].first<<" "<<v[i].second<<"-"<<v[i].first<<endl;
			if (v[start].second != v[i].second)
				minDiff = min(minDiff, v[i].first - v[start].first);
		}

		cout<<minDiff<<endl;
	}
 return 0;
}
