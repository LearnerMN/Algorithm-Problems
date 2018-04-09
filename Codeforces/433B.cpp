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
#define fors(i, a, b) for( int i = (a); i < (b); i++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
const double eps = 1e-9;
#define eq(x, y) (abs((x)-(y))<eps)
#define sqr(x) ((x)*(x))

int main(){
	int n;
	scanf("%d",&n);
	vector< int > v(n);
	vector< long long > sums(n+1);
	vector< long long > s2(n+1); 
	sums[0] = 0;
	fors(i,1,(n+1)){
		scanf("%d",&v[i-1]);
		sums[i] = sums[i-1] + v[i-1];
	}
	sort(v.begin(),v.end());
	s2[0] = 0;
	fors(i,1,n+1){
		s2[i] = s2[i-1] + v[i-1];
	}
	int q,a,r,l;
	scanf("%d",&q);
	while (q--){
		scanf("%d %d %d",&a,&l,&r);
		r;--l;
		pt((a == 1 ? (sums[r]-sums[l]) : (s2[r]-s2[l])));
	}
	return 0;
}