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


int findMin(vector< int > &v, int ind){
	int c = 0;
	for (int i=ind-1; i>=max(ind-5, 0); i--){
		if (v[ind] < v[i])
			c++;
	}
	return c;
}

int main(){
	freopen("input.txt", "r", stdin);

	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector< int > v(n); // = { 1, 2, 3, 4 };
		int ans = 1;
		for (int i=0; i<n; i++){
			cin>>v[i];
			if (i > 0){
				int num = findMin(v, i);
				if (i == num || num >= 5){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
 return 0;
}