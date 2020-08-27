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
		int c, r;
		cin>>c>>r;
		c = c / 9 + (c % 9 != 0);
		r = r / 9 + (r % 9 != 0);
		if (c < r){
			cout<<0<<" "<<c<<endl;
		}else{
			cout<<1<<" "<<r<<endl;
		}
	}
 return 0;
}
