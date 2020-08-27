#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>
#include <queue>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n, x, y;
		cin>>n;

		int rx = 0;
		int ry = 0;

		for (int i=0; i<4*n-1; i++){
			cin>>x>>y;
			rx ^= x;
			ry ^= y;
		}
		cout<<rx<<" "<<ry<<endl;
	}
	return 0;
}
