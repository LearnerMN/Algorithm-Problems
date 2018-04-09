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

int main(){
	int n,m;
	cin>>n>>m;
	vector< pair< int,int > > v;
	for (int i=0; i<n; i++){
		string s;
		cin>>s;
		for (int k=0; k<m; k++){
			if (s[k]!='*'){
				if (s[k]=='G'){
					for (int p=k+1; p<m; p++){
						if (s[p]=='S'){
							v.pb(mp(k,p));
							break;
						}
					}
				}
				break;
			}
		}
		
	}
	if (v.size()!=n){
		cout<<-1<<endl;
		return 0;
	}
	int c = 0;
	int mins = 0;
	while (mins!=INT_MAX){
		c++;
		mins = INT_MAX;
		for (int i=0; i<v.size(); i++){
			if (v[i].yy-v[i].xx>0){
				mins = min(mins,v[i].yy-v[i].xx);
			}
		}
		for (int i=0; i<v.size(); i++){
			v[i].yy -= mins;
		}
	}
	cout<<c-1<<endl;
 return 0;
}