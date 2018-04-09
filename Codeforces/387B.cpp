#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <cstdio>

#define xx first
#define yy second
#define pb push_back
#define mp make_pair

using namespace std;
int main(){
	int n,m,tmp;
	cin>>n>>m;
	vector< int > a(n);
	vector< int > b;
	vector< int > c;
	map< int,int > am,bm;
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int i=0; i<m; i++){
		cin>>tmp;
		bm[tmp]++;
		if (bm[tmp]==1)
			b.pb(tmp);
	}
	int ans = 0;
	for (int i=0; i<n; i++){
		if (bm[a[i]] > 0)
			bm[a[i]]--;
		else
			c.pb(a[i]);
	}
	sort(b.begin(),b.end());
	for (int i=0; i<c.size(); i++){
		bool ch = false;
		for (int j=0; j<b.size(); j++){
			if (bm[b[j]]>0 && c[i]<=b[j]){
				bm[b[j]]--;
				ch = true;
				break;
			}
		}
		if (!ch) ans++;
	}
	cout<<ans<<endl;
 return 0;
}