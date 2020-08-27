#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>

using namespace std;

int powerPlayer(int n){
	int res = 0;
	while (n > 0){
		res += n % 10;
		n /= 10;
	}
	return res;
}
int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n, a, b, p1 = 0, p2 = 0;
		cin>>n;
		for (int i=0; i<n; i++){
			cin>>a>>b;
			if (powerPlayer(a) > powerPlayer(b)){
				p1++;
			}else if (powerPlayer(b) > powerPlayer(a)){
				p2++;
			}else{
				p1++; p2++;
			}
		}
		if (p1 > p2){
			cout<<"0 "<<p1<<endl;
		}else if (p1 < p2){
			cout<<"1 "<<p2<<endl;
		}else{
			cout<<"2 "<<p1<<endl;
		}
	}
	return 0;
}
