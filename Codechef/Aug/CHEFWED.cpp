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


struct Node {
	int family;
	int cost;
	int total;
	map<int,int> mp;
	Node(int f, int c){
		family = f;
		cost = c;
		mp[f]++;
		total = 1;
	}

	void inc(int f){
		total++;
		mp[f]++;
	}

	void dec(int f){
		mp[f]--;
		total--;
	}
};
int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n, k, a;
		cin>>n>>k;
		vector<Node*> v;
		for (int i=0; i<n; i++){
			cin>>a;
			v.push_back(new Node(a, k));
		}
		// sort(v.begin(), v.end());
		while (v.size() > 1){
			for (int i=1; i<v.size(); i++){
				int integrate = v[i-1]
			}
		}

		int res = k;
		
		cout<<res<<endl;
	}
 return 0;
}
     