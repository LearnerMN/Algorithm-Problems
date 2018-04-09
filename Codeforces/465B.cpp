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
	int n,c=0;
	long long sums = 0;
	cin>>n;
	vector< int > v(n);
	vector< int > save;
	int tool = 0;
	fr (i,n){
		cin>>v[i];
		if (v[i] == 1){
			tool++;
		}else{
			if (tool != 0){
				c++;
				sums += tool;
			}
			tool = 0;
		}
	}
	if (tool != 0){
		c++;
		sums += tool;
	}
	if (c == 0)
		pt(0)
	else
		pt(sums + c-1)
    return 0;
}