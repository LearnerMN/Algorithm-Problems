#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <cstdio>

#define xx first
#define yy second
#define pb push_back
#define mp make_pair

using namespace std;
bool a[4010];
int main(){
	int x,k,z,t,n1,n2;
	cin>>x>>k;
	for (int i=0; i<k; i++){
		cin>>t;
		if (t==1){
			cin>>n1>>n2;
			a[n1] = true;
			a[n2] = true;
		}else{
			cin>>n2;
			a[n2] = true;
		}
	}
	int mins = 0, maxs = 0,c = 0;
	for (int i=1; i<x; i++)
		if (!a[i]){
			c++;
		}else{
			maxs += c;
			mins += (c%2==0 ? c/2 : c/2+1);
			c = 0;
		}
		maxs += c;
		mins += (c%2==0 ? c/2 : c/2+1);
	cout<<mins<<" "<<maxs<<endl; 
	
 return 0;
}