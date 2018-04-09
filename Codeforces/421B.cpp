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

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pt(st) (cout<<(st)<<endl);
#define fr(i,n) for (int i=0; i<(n); i++)
#define fors(i, a, b) for( int i = (a); i < (b); i++ )

using namespace std;
bool check(string s){
	string t = "AHIMOTUVWXY";
	for (int i=0; i<s.size(); i++){
		bool ch = false;
		for (int k=0; k<t.size(); k++){
			if (t[k]==s[i]){
				ch = true;
				break;
			}
		}
		if (!ch)
			return false;
	}
	return true;
}
int main(){
	string s,m;
	cin>>s;
	m = s;
	reverse(s.begin(),s.end());
	if ((m == s) && (check(m))){
		pt("YES")
	}else{
		pt("NO")
	}
 return 0;
}