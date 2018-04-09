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
#define sf(n) (scanf("%d",&(n)));

int main(){
	long long n,l;
	cin>>n>>l;
	vector< long long > v(n);
	fr (i,n){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	double mins = max(v[0],l-v[n-1]);
	v.pb(0);
	v.pb(l);
	sort(v.begin(),v.end());
	double maxs = -1;
	frs (i,1,v.size()){
		maxs = max((double)(v[i]-v[i-1])/2,maxs);
	}
	printf("%.10llf\n",max(maxs,mins));
    return 0;
}