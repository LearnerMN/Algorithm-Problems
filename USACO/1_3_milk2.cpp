// https://train.usaco.org/usacoprob2?a=iv2UF2vraH3&S=milk2

/*
ID: learner2
LANG: C++11
PROB: milk2
*/

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

using namespace std;


int main(){
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	int n = 3;
	vector< pair< int, int > > v; // = { { 300, 1000 }, {700, 1200 }, { 1500, 2100 } };
	cin>>n;
	for (int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		v.push_back(make_pair(a, b));
	}
	
	sort(v.begin(), v.end());

	int l = v[0].first;
	int r = v[0].second;
	int longest_time = 0;
	int longest_idle = 0;
	for (int i=1; i<n; i++){
		if (r >= v[i].first){
			r = max(v[i].second, r);
			l = min(l, v[i].first);
		} else{
			longest_idle = max(longest_idle, v[i].first - r);
			longest_time = max(longest_time, r - l);
			l = v[i].first;
			r = v[i].second;
		}
	}
	longest_idle = max(longest_idle, v.back().first - r);
	longest_time = max(longest_time, r - l);

	cout<<longest_time<<" "<<longest_idle<<endl;
 return 0;
}
