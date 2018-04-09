//http://codeforces.com/problemset/problem/505/A
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

char save = 'a';
bool isPal(string s){
	for (int i=0,t=s.size()-1; i<s.size()/2; t--,i++){
		if (s[i] != s[t]){
			if (s[i] == '!' || s[t] == '!'){
				save = (s[i] == '!' ? s[t] : s[i]);
				continue;
			}
			return false;
		}
	}
	return true;
}
int sCh(string s){
	for (int i=0; i<s.size(); i++){
		if (s[i] == '!'){
			return i;
		}
	}
	return -1;
}
int main(){
	string s;
	cin>>s;
	
	string t = "";
	for (int i=0; i<s.size(); i++){
		t = s;
		t.insert(t.begin()+i,'!');
		if (isPal(t)){
			int ind = sCh(t);
			if (ind != -1){
				t[ind] = save;
			}
			cout<<t<<endl;
			return 0;
		}
	}
	t = s;
	t += '!';
	if (isPal(t)){
		int ind = sCh(t);
		if (ind != -1){
			t[ind] = save;
		}
		cout<<t<<endl;
		return 0;
	}
	cout<<"NA"<<endl;
    return 0;
}
