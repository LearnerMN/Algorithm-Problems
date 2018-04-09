#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,t,c,a,v=0,l=0,d;
	cin>>n>>t>>c;
	for (int i=0; i<n; i++){
		cin>>a;
		if (t<a){
			d = v-c+1;
			l += (d<0 ? 0 : d);
			v = 0;
			continue;	
		} 
		v++;
	}
	d = v-c+1;
	l += (d<0 ? 0 : d);
	cout<<l<<endl;
	return 0;
}