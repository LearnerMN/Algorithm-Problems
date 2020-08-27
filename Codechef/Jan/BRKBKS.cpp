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
		unsigned long long s, a, b, c;
		cin>>s>>a>>b>>c;
		if (a + b + s <= s){
			cout<<1<<endl;
		}else if (a + b <= s || b + c <= s){
			cout<<2<<endl;
		}else{
			cout<<3<<endl;
		}
	}
 return 0;
}
