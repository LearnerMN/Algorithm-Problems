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
		int k, n;
		cin>>n>>k;
		vector< int > v(n); // = { 1, 2, 3, 4 };
		for (int i=0; i<n; i++){
			cin>>v[i];
		}
		map< int,int > mp;
		for (int i=0; i<(1<<n); i++){
			int s = 0, c = 0;
			for (int j=0; j<n; j++){
				if (i&(1<<j)){
					s += v[j]; c++;
				}
			}
			if (c == k){
				mp[s]++;
			}
		}
		if (mp.size() != 0)
			cout<<((*--mp.rend()).second)<<endl;
		else
			cout<<1<<endl;
	}
 return 0;
}