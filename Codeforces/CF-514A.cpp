//http://codeforces.com/problemset/problem/514/A
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

char minS(char a,int i){
	if (i == 0 && '9' - a == 0){
		return a;
	}
	if (('9'- a) > a-48){
		return a;
	}else
		return ('9'- a)+48;
}

int main(){
	string s;
	cin>>s;
	string res = "";
	fr (i,s.size()){
		res += minS(s[i],i);
	}
	cout<<res<<endl;
    return 0;
}
