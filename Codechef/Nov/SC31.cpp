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
		cin>>n;
		vector<string> v;
		for (int i=0; i<n; i++){
			string s;
			cin>>s;
			v.push_back(s);
		}
		int res = 0;
		for (int k=0; k<10; k++){
			int c = 0;
			for (int i=0; i<n; i++){
				if (v[i][k] == '1'){
					c++;
				}
			}
			res += (c&1);
		}
		cout<<res<<endl;
	}
 return 0;
}
