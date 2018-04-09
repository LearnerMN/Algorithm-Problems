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

long long toInt(string s){
	istringstream buffer(s);
	long long value;
	buffer >> value;
	return value; 
}

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

map< pair< int,int >,bool > mps;
long long isCheck(int x,int y,int x1,int y1,int x2,int y2){
	long long s=(long long)((long long)(x-x1)*(y+y1)+(long long)(x1-x2)*(y1+y2)+(long long)(x2-x)*(y2+y));
	return s;	
}
int main(){
	int n;
	pair< int,int > p1;
	cin>>n>>p1.xx>>p1.yy;
	vector< pair< int,int > > v;
	for (int i=0; i<n; i++){
		pair< int,int > pp;
		cin>>pp.xx>>pp.yy;
		v.pb(pp);
	}
	int tool = 0;
	while (!v.empty()){
		for (int i=1; i<v.size(); i++){
			if (i<1) break;
			if (isCheck(p1.xx,p1.yy,v[0].xx,v[0].yy,v[i].xx,v[i].yy) == 0){
				v.erase(v.begin()+i);
				i--;
			}
		}
		v.erase(v.begin());
		tool++;
	}
	cout<<tool<<endl;
	return 0;
}