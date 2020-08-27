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
	// freopen("marm_02.txt", "w", stdout);
	int t;
	cin>>t;
	while (t--){
		int n;
		long long k;
		cin>>n>>k;
		vector<int> v(n);
		for (int i=0; i<n; i++){
			cin>>v[i];
		}
		
        k = k % (n*3);// + (k == 0 ? 3 : k);

		for (int i=0; i<k; i++){
			v[i % n] = v[i % n] ^ v[n - i%n - 1];
		}
		for (int i=0; i<n; i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
 return 0;
}
/*
11 11 11 3 3 5 4 3 2 1
11 11 11 3 3 5 4 3 2 1 

10 11 11 3 3 5 4 3 2 1 
10 11 11 3 3 5 4 3 2 1 

11 11 11 3 3 5 7 8 9 10 
11 11 11 3 3 5 7 8 9 10 

6
4 4
1 2 3 4
4 8
1 2 3 4
4 12
1 2 3 4
4 16
1 2 3 4
4 20
1 2 3 4
4 207
1 2 3 4




5 1 2 1 
4 3 1 5 
1 2 3 4 
5 1 2 1 
4 3 1 5 
5 1 2 4 

*/