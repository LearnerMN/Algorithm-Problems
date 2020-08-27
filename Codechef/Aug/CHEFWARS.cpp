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
		int n, p;
		cin>>n>>p;
		while (n > 0 && p > 0 ){
			n -= p;
			p >>= 1;
		}
		cout<<(n <= 0)<<endl;
	}
 return 0;
}
