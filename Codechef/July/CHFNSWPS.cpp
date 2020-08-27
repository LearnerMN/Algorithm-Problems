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
		int n, a, b;
		cin>>n;
		map<int,int> mp;
		for (int i=0; i<n; i++){
			cin>>a;
			mp[a]++;
		}
		for (int i=0; i<n; i++){
			cin>>b;
			mp[b]--;
		}
		bool check = true;
		int s = 0;
		vector<int> x, y;
		for (auto p : mp){
		    int d = abs(p.second);
			if (d&1){
				check = false;
				break;
			}
			
			while (d > 1){
				if (p.second > 0){
					x.push_back(p.first);
				}else if (p.second < 0){
					y.push_back(p.first);
				};
				d /= 2;
			}
			s += p.second;
		}
		if (check && x.size() == y.size() && s == 0){
			sort(x.begin(), x.end());
			sort(y.begin(), y.end());
			int t = x.size();
			long long res = 0;
			int l1 = 0, r1 = t-1;
			int l2 = 0, r2 = t-1;
			while (t > 0 && l1 <= r1 && l2 <= r2){
				if (x[l1] <= y[l2]){
					res += x[l1];
					l1++;
					r2--;
				}else if (x[l1] > y[l2]){
					res += y[l2];
					l2++;
					r1--;
				}
				t--;
			}
			
			cout<<res<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
