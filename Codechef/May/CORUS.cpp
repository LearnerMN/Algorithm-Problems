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
		int n, q;
		cin>>n>>q;
		string s;
		cin>>s;
		map<char,int> mp;
		for (auto &ch : s){
			mp[ch]++;
		}
		for (int i=0; i<q; i++){
			int c, res = 0;
			cin>>c;
			for (auto p : mp){
				res += max(0, p.second - c);
			}
			cout<<res<<endl;
		}
		
	}
 return 0;
}