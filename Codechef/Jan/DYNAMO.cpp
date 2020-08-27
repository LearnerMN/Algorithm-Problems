#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <set>

using namespace std;

unsigned long long mx(int n){
	unsigned long long s = 0;
	for (int i=0; i<n; i++){
		s = s*10 + 9;
	}
	return s;
}
int main(){
	freopen("input.txt", "r", stdin);
	int t, n, r;
	cin>>t;
	while (t--){
		cin>>n;

		unsigned long long a, b, c, d, e, s, p;
		p = mx(n);
		cin>>a;
		s = (p+1) * 2 + a;
		cout<<s<<endl<<flush;
		s -= a;

		cin>>b;
		s -= b;
		cout<<1 + (p - b)<<endl<<flush;
		s -= (1 + (p - b));

		cin>>d;
		s -= d;

		cout<<s<<endl<<flush;

		cin>>r;
	}
 return 0;
}
