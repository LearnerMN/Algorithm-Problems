#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
static long long as=1;
long long dif(long long a, long long b, long long c){
	if (a>b){
		as = a;
		return a-b; 
	}else if(a<b) {
		as = a;
		return (c-b)+a;
	}else{
		return 0;
	}
}
int main()
{
	long long res=0,n,m,x,a;
	cin>>n>>m;
	x=m;
	while (x--){
		cin>>a;
		res+=dif(a,as,n);
	}
	cout<<res<<endl;
	
}