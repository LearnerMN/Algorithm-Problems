#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>

using namespace std;


int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n, f = 0, t = 0, a;
		cin>>n;
		bool done = true;
		for (int i=0; i<n; i++){
			cin>>a;
			if (!done) continue;

			if (a == 5){
				f++;
			}else if (a == 10){
				if (f < 1){
					done = false;
					continue;
				}
				f--, t++;
			}else{
				if (t > 0){
					t--;
				} else if (f > 1){
					f -= 2;
				}else {
					done = false;
					continue;
				}
			}
		}
		cout<<(done ? "YES" : "NO")<<endl;
	}
	return 0;
}

/*

xyxxy
011


*/