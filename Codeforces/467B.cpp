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
int n;
string DecimalToBinaryString(int a)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < n; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    return binary;
}

int yalga(int a,int b){
	int cc = 0;
	string c = DecimalToBinaryString(a);
	string d = DecimalToBinaryString(b);
	for(int i = 0; i < n; i++)
    {
        if (c[i] != d[i]) cc++;
    }
	return cc;
}


int main(){
	pt(DecimalToBinaryString(4));
	int m,k,b,tool = 0,t;
	cin>>n>>m>>k;
	vector< int > v(m);
	fr (i,m){
		cin>>v[i];
	}
	cin>>t;
	fr (i,m){
		if (yalga(t,v[i])<=k) tool++;
	}
	pt(tool);
    return 0;
}