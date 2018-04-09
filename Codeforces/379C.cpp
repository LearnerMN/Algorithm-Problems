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
struct abc{
	int ind;
	long value;
};
bool cmp1(abc a, abc b){
	return a.ind < b.ind;
}
bool cmp2(abc a, abc b){
	return a.value < b.value;
}
int main(){
	int n,a;
	cin>>n;
	vector<abc> v(n);
	for (int i=0; i<n; i++){
		cin>>a;
		v[i].ind  = i;
		v[i].value = a;
	}
	sort(v.begin(),v.end(),cmp2);
	for (int i=1; i<n; i++){
		if (v[i-1].value>=v[i].value)
			v[i].value = v[i-1].value + 1;
	}
	sort(v.begin(),v.end(),cmp1);
	for (int i=0; i<n; i++){
		cout<<v[i].value<<" ";
	}
 return 0;
}