//http://codeforces.com/problemset/problem/509/B
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

using namespace std;

template<typename T> string toStr(T x) { stringstream ss; ss << x; return ss.str(); }
template<typename T> T pows(T base, T exp){ T res = 1; while (exp > 0){ if (exp % 2 == 1) res = (res * base); exp = exp >> 1; base = (base * base); } return res; }
//shortcuts
#define all(_xx) _xx.begin(), _xx.end()

#define gcd __gcd
#define lcm(a,b) a*b/gcd(a,b)

#define xx first
#define yy second
#define pb push_back
#define mp make_pair

//print
#define pt(st) (cout<<(st)<<endl);

// loop
#define fr(i,n) for (int i=0; i<(n); i++)
#define frs(i, a, b) for( int i = (a); i < (b); i++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
const double eps = 1e-9;
#define eq(x, y) (abs((x)-(y))<eps)
#define sqr(x) ((x)*(x))

int main(){
	int n,K;
	cin>>n>>K;
	vector< int > t(n);
	for (int i=0; i<n; i++){
		cin>>t[i];
	}
	vector< vector< int > > v;
	for (int i=0; i<n; i++){
		vector< int > cache;
		if (t[i] > K){
			for (int k = 0; k<K; k++){
				cache.pb(0);
			}
			int d = t[i];
			while (d > 0){
				cache[(d-1)%K]++;
				d--;
			}
		}else{
			for (int k=0; k<K; k++){
				if (t[i]<=k){
					cache.pb(0);
				}else{
					cache.pb(1);
				}
			}
		}
		v.pb(cache);
	}
	
	
	for (int i=0; i<K; i++){
		for (int k=0; k<n-1; k++){
			for (int j=k+1; j<n; j++){
				if (v[k][i] - v[j][i] > 1){
					pt("NO")
					return 0;
				}
			}
		}
	}
	
	pt("YES")
	for (int i=0; i<n; i++){
		for (int k=0; k<v[i].size(); k++){
			for (int p=0; p<v[i][k]; p++){
				cout<<k+1<<" ";
			}
			
		}
		cout<<endl;
	}
    return 0;
}
