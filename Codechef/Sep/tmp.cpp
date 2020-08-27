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
    int n;
    cin>>n;
    vector< int > v(n);
    vector< pair< int,int > > vp;
    vector< long long > msum(n+1, 0);
    for (int i=0; i<n; i++){
    	cin>>v[i];
    	vp.push_back(make_pair(v[i], i));
    	msum[i+1] = msum[i] + v[i];
    }
    sort(vp.begin(), vp.end());
    int q;
    cin>>q;
    while (q--){
    	int l, r;
    	long long y;
    	cin>>l>>r>>y;
    	--l; r--;
    	long long diff = msum[r+1] - msum[l];
    	if (y > diff){
    		cout<<-1<<endl;
    	}else{
    		for (int i=vp.size()-1; i>0; i--){
    			if (l <= vp[i].second && vp[i].second <= r){
    				if (diff - vp[i].first >= y){
    					diff -= vp[i].first;
    				}else{
    					break;
    				}
    			}
    		}
    		printf("%lld\n", diff);
    	}
    }
 return 0;
}

/*

[-1,5,-7,2,-1,0,7,6,2,4]
5


*/