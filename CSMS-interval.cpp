//http://www.spoj.com/CSMS/problems/CSMS141/
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
#define ABS(x) ((x<0) ? (-(x)) : (x))
using namespace std;

int main(){
	int n,a;
	scanf("%d",&n);
	vector< long long > v(n+1);
	v[0] = 0;
	for (int i=1; i<=n; i++){
		scanf("%d ",&a);
		v[i] = v[i-1] + a;
	}
	int q;
	scanf("%d",&q);
	while (q--){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%lld\n",v[y]-v[x-1]+(x+y)*(y-x+1)/2);
	}
 return 0;
}
