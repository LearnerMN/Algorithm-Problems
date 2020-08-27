#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <set>

using namespace std;


int main(){
// 	freopen("input.txt", "r", stdin);

	int t;
	cin>>t;
	while (t--){
		int n, m, q, x, y;
		cin>>n>>m>>q;
		map<int,bool> mpX;
		map<int,bool> mpY;
		for (int i=0; i<q; i++){
			cin>>x>>y;
			mpX[x] = !mpX[x];
			mpY[y] = !mpY[y];
		}
		int fOdd = 0, fEven = 0;
		for (auto i : mpX){
		    if (i.second & 1){
		        fOdd++;
		    }else{
		        fEven++;
		    }
		}
		
		int sOdd = 0, sEven = 0;
		for (auto i : mpY){
		    if (i.second & 1){
		        sOdd++;
		    }else{
		        sEven++;
		    }
		}
		int res = fOdd * sEven + fEven * sOdd + fOdd * (m - mpY.size()) + sOdd * (n - mpX.size());
		cout<<res<<endl;
	}
 return 0;
}