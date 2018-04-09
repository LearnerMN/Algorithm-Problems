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
int a[101][101];
int b[101][101];
int n,m;
bool check(){
	for (int i=0; i<n; i++){
		for (int k=0; k<m; k++){
			b[i][k] = -11;
		}
	}
	for (int i=0; i<n; i++){
		for (int k=0; k<m; k++){
			if (!a[i][k]){
				for (int x=0; x<m;x++){
					b[i][x] = 0;
				}
				for (int x=0; x<n;x++){
					b[x][k] = 0;
				}
			}
		}
	}
	for (int i=0; i<n; i++){
		for (int k=0; k<m; k++){
			if (b[i][k] != 0){
				b[i][k] = 1;
			}
		}
	}
	
	for (int i=0; i<n; i++){
		for (int k=0; k<m; k++){
			int c = 0;
			for (int x=0; x<m;x++){
				c |= b[i][x];
			}
			for (int x=0; x<n;x++){
				c |= b[x][k];
			}
			if (c != a[i][k]) return false;
		}
	}
	
	return true;
}

int main(){
	cin>>n>>m;
	for (int i=0; i<n; i++){
		for (int k=0; k<m; k++){
			cin>>a[i][k];
		}
	}
	if (check()){
		pt("YES")
		for (int i=0; i<n; i++){
			for (int k=0; k<m; k++){
				cout<<b[i][k]<<" ";
			}
			cout<<endl;
		}
	}else{
		pt("NO")
	}
    return 0;
}