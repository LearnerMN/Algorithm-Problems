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
		int n, k, p;
		cin>>n>>k;
		int res = 0;
		for (int i=0; i<n; i++){
			cin>>p;
			int diff = p - k;
			res += diff > 0 ? diff : 0;
		}
		cout<<res<<endl;
	}
	return 0;
}