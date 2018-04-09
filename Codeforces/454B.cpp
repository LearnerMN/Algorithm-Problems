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
	int n;
	cin>>n;
	vector< int > v(n);
	fr (i,n){
		cin>>v[i];
	}
	fr (i,n){
		v.pb(v[i]);
	}
	bool check = false;
	int c = 0;
	int maxs = 0;
	int mins = 0;
	
	
	frs (i,1,v.size()){
		if (v[i-1]<=v[i]){
			c++;
			check = true;
			if (c == n){
				pt(i == n ? 0 : n*2 - i);
				return 0;
			}
				
		}else{
			if (check){
				maxs = max(maxs,c);
			}
			if (maxs + 1 == n){
				mins = i;
				check = false;
				break;
			}
			c = 0;
			check = false;
		}
	}	
	if (check){
		maxs = max(maxs,c);
		mins = n*2;
	}
	if (maxs + 1 == n){
		pt(mins == n ? 0 : n*2 - mins);
	}else{
		pt("-1")
	}
    return 0;
}
//3 1 2 3 1 2 
//2 3 4 5 1 