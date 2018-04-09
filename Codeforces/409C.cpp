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
int a[5];
int t[5] = {1,1,2,7,4};
bool checks(){
	for (int i=0; i<5; i++){
		if (a[i]<t[i]){
			return false;
		}
	}
	return true;
}
int main(){
	
	int b,c=0;
	while (cin>>b){
		a[c++]= b;
		if (c>4)
			break;
	}
	int q=0;
	while (checks()){
		q++;
		for (int i=0; i<5; i++){
			a[i] -= t[i];
		}
	}
	cout<<q<<endl;
 return 0;
}