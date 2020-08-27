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


int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n, k, a;
		cin>>n>>k;
		int res = -1, mins = INT_MAX;
		for (int i=0; i<n; i++){
			cin>>a;
			if (k % a == 0 && k >= a && mins > k/a) {
				res = a;
				mins = k/a;
			}
		}
		cout<<res<<endl;
	}
 return 0;
}
