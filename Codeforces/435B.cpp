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

string s;
int p = 0,K;
int maxI(int k){
	int save = p;
	char maxs = s[p];
	for (int i=p+1; i<p+k+1 && i<s.size();i++){
		if (maxs < s[i] && s[i]>'0'){
			maxs = s[i];
			save = i;
		}
	}
	return save;
}
void swaps(int d){
	char a = s[d];
	s.erase(s.begin()+d);
	s.insert(s.begin()+p,a);
	if (p<d){
		K -= (d-p);	
	}else{
		K=0;
	}
	
}
int main(){
	cin>>s>>K;
	while (K>0 && p<s.size()){
		int l = maxI(K);
		if (l!=p){
			swaps(l);
		}else
			p++;
	}
	cout<<s<<endl;
    return 0;
}