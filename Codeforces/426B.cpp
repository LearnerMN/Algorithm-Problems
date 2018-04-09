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
#define pt(st) (cout<<(st)<<endl);
#define fr(i,n) for (int i=0; i<(n); i++)
#define fors(i, a, b) for( int i = (a); i < (b); i++ )

using namespace std;
vector< vector< int > > v;
int n,m;
bool check(){
	if ((n==0) || (n%2 != 0)){
		return false;
	}
	for (int i=0,t=n-1; i<n/2; i++,t--){
		for (int k=0; k<m; k++){
			if (v[t][k] != v[i][k]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=0; i<n; i++){
		vector< int > vec(m);
		for (int k=0; k<m; k++){
			scanf("%d",&vec[k]);
		}
		v.pb(vec);
	}
	while (check()){
		n /= 2;
	}
	printf("%d",n);
 return 0;
}