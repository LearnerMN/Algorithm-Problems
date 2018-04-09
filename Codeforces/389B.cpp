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
vector< string > v(101);
bool finish(){
	for (int i=0; i<n; i++){
		for (int j=0; j<n;j++){
			if (v[i][j]=='#'){
				return false;
			}
		}
	}
	return true;
}
void check(int x,int y){
	if (v[x][y+1]=='#' && v[x+1][y+1]=='#' && v[x+1][y]=='#' && v[x+1][y+2]=='#' && v[x+2][y+1]=='#'){
		v[x][y+1]='.';
		v[x+1][y+1]='.';
		v[x+1][y]='.';
		v[x+1][y+2]='.';
		v[x+2][y+1]='.';
	}
}
int main(){
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>v[i];
	}
	if ((v[n-1][n-1]=='#') || (v[0][0]=='#') || (v[n-1][0]=='#') || (v[0][n-1]=='#')){
		cout<<"NO"<<endl;
		return 0;
	}
	for (int i=0; i<n-2; i++){
		for (int j=0; j<n-2; j++){
			check(i,j);
		}
	}
	if (finish()){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
 return 0;
}