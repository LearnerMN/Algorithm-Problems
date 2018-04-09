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


int checkXY(pair< int,int > a,pair< int,int > b,int t){
	b.xx += t;
	b.yy += t;
	
	if (b.xx<=a.xx && a.yy<=b.yy){
		return a.yy - a.xx;
	}else
	if (a.xx<=b.xx && b.yy<=a.yy){
		return b.yy - b.xx;
	}else
	if (b.xx <= a.xx && b.yy<=a.yy){
		return b.yy - a.xx;
	}else
	if (a.xx <= b.xx && a.yy<=b.yy){
		return a.yy - b.xx;
	}else{
		return -1;
	}
}
bool cmp(pair< int,int > a,pair< int,int > b){
	return a.xx<b.xx || a.yy < b.yy;
}
int main(){
	int p,q,l,r,x,y;
	cin>>p>>q>>l>>r;
	vector< pair< int,int > > a,b;
	fr (i,p){
		cin>>x>>y;
		a.pb(mp(x,y));
	}
	fr (i,q){
		cin>>x>>y;
		b.pb(mp(x,y));
	}
	int tool = 0;
	for (int t=l;t<=r;t++){
		for (int i=0; i<p; i++){
			for (int k=0; k<q; k++){
				if (0 <= checkXY(a[i],b[k],t)) {
					tool++;
					goto ends;
				}
			}
			
		}	
		ends:
		int xx = 0;
	}
	
	pt(tool)
	
    return 0;
}