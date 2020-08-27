#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>

using namespace std;


int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for (int i=0; i<n; i++){
			cin>>v[i];
		}
		long long res = 0;
		for (int i=1; i<n; i++){
			int d = v[i] > v[i-1] ? v[i] - v[i-1] : v[i-1] - v[i];
			res += d - 1;
		}
		cout<<res<<endl;
	}
	return 0;
}

/*

xyxxy
011


*/