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
	int n;
	cin>>n;
	string s;
	cin>>s;
	s += ".";
	s = "." + s;
	char save = '.';
	int c=0,k=0,m=0;
	for (int i=1; i<=n; i++){
		if (save=='.' && s[i]=='L'){
			c=0;k=i;save = 'L';
		}else
		if (save=='.' && s[i]=='R'){
			m += c;
			c=0;k=i;save = 'R';
		}else
		if (save=='L' && s[i]=='L'){
			
			c=0;k=i;save = 'L';
		}else
		if (save=='L' && s[i]=='R'){
			m += c;
			c=0;k=i;save = 'R';
		}else
		if (save=='R' && s[i]=='L'){
			m += ((c%2==1) ? 1:0);
			c=0;k=i;save = 'L';
		}else
		if (save=='R' && s[i]=='R'){
			c=0;k=i;save = 'R';
		}else{
			c++;
		}
		
	}
	if (c!=0 && save !='R')
		m += c;
	cout<<m<<endl;
 return 0;
}