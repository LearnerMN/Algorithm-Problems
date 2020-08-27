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
		unsigned long long x, y, l, r;
		cin>>x>>y>>l>>r;
		unsigned long long maxZ = x | y, z = l, maxs = 0;
		if (maxZ <= r){
			z = maxZ;
		}else{
			vector<int> v;
			while (maxZ > 0){
				v.insert(v.begin(), maxZ&1);
				maxZ >>= 1;
			}
			unsigned long long n = v.size();
			for (int i=0; i<(1<<n); i++){
				unsigned long long p = 0;
				for (int j=0, t=n-1; j<n; j++, t--){
					if ((i & (1<<j)) && v[j]){
						p += pow(2, t);
					}
				}
				// cout<<p<<endl;
				unsigned long long ew = (x&p) * (y&p);
				if (p <= r && (ew > maxs || (ew == maxs && p < z))){
					z = p;
					maxs = ew;
				}
			}
		}
		
		cout<<z<<endl;
	}
	return 0;
}