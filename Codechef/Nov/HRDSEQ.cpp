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
		int n;
		cin>>n;
		map< int, int > mp;
		int last = 0;
		vector<int> v;
		v.push_back(last);

		for (int i=0; i<n-1; i++){
			bool isFound = false;
			for (int k=i-1; k>=0; k--){
				if (v[k] == last){
					isFound = true;
					v.push_back(i-k);
					last = i-k;
					break;
				}
			}
			if (!isFound){
				v.push_back(0);
				last = 0;
			}
		}
		int res = 0;
		for (auto i : v)
			res += (i == last);
		cout<<res<<endl;
	}
 return 0;
}
