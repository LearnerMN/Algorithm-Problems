#include <cstdio>
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
		int mins = INT_MAX, maxs = 1;
		vector<int> v(n);
		for (int i=0; i<n; i++){
			cin>>v[i];
		}
		int count = 1;
		for (int i=1; i<n; i++){
			if (v[i] - v[i-1] < 3){
				count++;
			}else{
				mins = min(mins, count);
				maxs = max(maxs, count);
				count = 1;
			}
			// cout<<count<<" ";
		}
		// cout<<endl;
		mins = min(mins, count);
		maxs = max(maxs, count);
		cout<<mins<<" "<<maxs<<endl;
	}
 return 0;
}