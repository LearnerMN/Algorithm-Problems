#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>

using namespace std;
map< int,int > mp;
int main(){
	int n,m,z;
	cin>>n>>m;
	int a[n+1];
	int b[n+1];
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int i=n-1; i>=0; i--){
		mp[a[i]] = 1;
		b[i] = mp.size(); 
	}
	while (m--){
		cin>>z;
		cout<<b[--z]<<endl;
	}
 return 0;
}