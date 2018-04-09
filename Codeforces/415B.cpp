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
	long long n,a,b,p;
	cin>>n>>a>>b;
	for (int i=0; i<n; i++){
		cin>>p;
		cout<<((p*a)%b )/a<<endl;
	}

 return 0;
}