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
	int cp=0,cn = 0,t=0,xp = 0,xn = 0;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	for (int i=0; i<s1.size(); i++){
		
		if (s1[i] == '+')
			cp++;
		if (s1[i] == '-')
			cn++;
		if (s2[i] == '?') 
			t++;
		if (s2[i] == '+')
			xp++;
		if (s2[i] == '-')
			xn++;
	}
	int cc = 0;
	for (int i=0; i<(1<<t); i++){
		int tp = 0,tn = 0;
		for (int k=0; k<t; k++){
			if ((1<<k)&i){
				tp++;
			}else{
				tn++;
			}
		}
		if (tp+xp == cp && tn+xn == cn){
			cc++;
		}
	}
	printf("%.12llf",(double)cc/ (1<<t));
    return 0;
}