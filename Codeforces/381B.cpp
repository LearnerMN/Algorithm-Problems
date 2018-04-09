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

int a[5000];
int main(){
	int n,p,c=0,l=0;
	cin>>n;
	int maxs = -1;
	for (int i=0; i<n; i++){
		cin>>p;
		maxs = max(maxs,p);
		a[p]++;
	}
	for (int i=0; i<maxs; i++){
		if (a[i]!=0) c++;
		if (a[i]>1) c++;
	}
	cout<<c+1<<endl;
	for (int i=0; i<maxs; i++){
		if (a[i]>1)
			cout<<i<<" ";
	}
	for (int i=maxs; i>=0; i--){
		if (a[i]!=0)
			cout<<i<<" ";
	}
	
 return 0;
}