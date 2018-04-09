//http://www.spoj.com/CSMS/problems/CSMS135/
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

using namespace std;
map< int,int > mp;
int main(){
	//freopen("test9.txt", "r", stdin);
	//freopen("test9.out", "w", stdout);
	int n,m,z;
	//cin>>n>>m;
        scanf("%d%d",&n,&m);
	int a[n+1];
	int b[n+1];
	for (int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for (int i=n-1; i>=0; i--){
		mp[a[i]] = 1;
		b[i] = mp.size(); 
	}
	while (m--){
		scanf("%d",&z);
                printf("%d\n",b[--z]);
	}
 return 0;
}
