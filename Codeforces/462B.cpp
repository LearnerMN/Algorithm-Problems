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
	vector< int > v;
	fr (i,26){
		v.pb(0);
	}
	int n,k;
	string st;
	cin>>n>>k;
	cin>>st;
	fr (i,n){
		v[(int)st[i]-65]++;
	}
	sort(v.begin(),v.end());
	
	while(v[0] == 0){
		v.erase(v.begin());
	}
	long long sums = 0;
	while (k>=v[v.size()-1]){
		k -= v[v.size()-1];
		long long d = (long long)v[v.size()-1];
		sums += d*d;
		v.pop_back();
	}
	sums += (long long)k*k;
	pt(sums)
    return 0;
}