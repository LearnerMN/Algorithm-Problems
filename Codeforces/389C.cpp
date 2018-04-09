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
int n;
bool ch[101];
bool finish(){
	for (int i=0; i<n; i++){
		if (!ch[i])
			return false;
	}
	return true;
}
map< int,int > m;
int main(){
	cin>>n;
	vector< int > v(n);
	int c=0;
	for (int i=0; i<n; i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	
	while (!finish()){
		int save = 0;
		for (int i=0; i<n; i++){
			if (!ch[i]){
				save = i;
				ch[i] = true;
				break;
			}
		}
		int mins = v[save];
		for (int i=save; i<n; i++){
			if (((mins<v[i]) || (mins!=0 && mins==v[i])) && !ch[i]){
				if (m[c]<v[i]){
					mins = v[i];
					ch[i] = true;
					m[c]++;
				}
			}
		}
		c++;
	}
	cout<<c<<endl;
 return 0;
}