//http://www.spoj.com/CSMS/problems/ULS11101/
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
map <long long, long long> F;
long long t,n,f[1000001],z=0,i,a,b,c;
void calc(){
	a=1;b=1;
  	while (b<=n){ 
		f[++z] = b;
		c = b;
		b = a+b;
		a = c;
	}
}
long long sum(long long n){ 
	if (n==0) return 0;
  	if (F.count(n)) 
		return F[n];
  	for (int i=z; i>=1 ;i--)
     	if (f[i]<=n){
			long long m = n-f[i]+1;
       		F[n] = sum(f[i]-1) + sum(m-1) + m;
    	return F[n];
    }
}
int main(){ 
	scanf("%lld",&t);
    while (t--){ 
		scanf("%lld",&n);
        F.clear();
      	calc();
		printf("%lld\n",sum(n));
	}
	return 0;
}
