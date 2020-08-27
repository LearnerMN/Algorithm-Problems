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
		string s, p;
		cin>>s>>p;
		for (auto &ch : p){
			s.erase(s.find(ch), 1);
		}

		sort(s.begin(), s.end());
		string tmp(s.begin(), s.end());
		s.insert(upper_bound(s.begin(), s.end(), p[0]), p.begin(), p.end());
		tmp.insert(lower_bound(tmp.begin(), tmp.end(), p[0]), p.begin(), p.end());
		cout<<min(s, tmp)<<endl;
	}
 return 0;
}
