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

pair< int, int > longestIncreasing(vector<int> &v, int l, int r){
	int mx = 1, t = 1, mc = 1;
	for (int i=l; i<r; i++){
		if (v[i-1] < v[i]){
			t++;
		}else{
			if (t == mx){
				mc++;
			}else if (t > mx){
				mc = 1;
				mx = t;
			}
			t = 1;
		}
	}

	if (t == mx){
		mc++;
	}else if (t > mx){
		mc = 1;
		mx = t;
	}
	if (mx == 1) mc = 0;
	return { mx, mc };
}

pair< int, int > longestDecreasing(vector<int> &v, int l, int r){
	int mx = 1, t = 1, mc = 1;
	for (int i=l; i<r; i++){
		if (v[i-1] > v[i]){
			t++;
		}else{
			if (t == mx){
				mc++;
			}else if (t > mx){
				mc = 1;
				mx = t;
			}
			t = 1;
		}
	}

	if (t == mx){
		mc++;
	}else if (t > mx){
		mc = 1;
		mx = t;
	}
	if (mx == 1) mc = 0;
	return { mx, mc };
}

int main(){
	freopen("input.txt", "r", stdin);
	int n, q;
	cin>>n>>q;
	vector<int> v(n);
	for (int i=0; i<n; i++){
		cin>>v[i];
	}
	while (q-- > 0){
		int l, r;
		cin>>l>>r;
		auto x = longestIncreasing(v, l, r);
		auto y = longestDecreasing(v, l, r);
		cout<<(x.second == y.second ? "YES" : "NO")<<endl;
	}
 return 0;
}
