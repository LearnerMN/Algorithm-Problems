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

using namespace std;

int largestPower(int n){
	int r = 1;
	while (n > 1){
	    n = n >> 1;
		r = (r << 1) % 60;
	}
	return r;
}


int main(){
	int r = 15;

	cout<<largestPower(r)<<endl;
	//                         // 0, 1, 1, 2, 3, 5, 8, 3, 1
	// vector< int > cache = { 0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1 };
	// int t = 1;
	// cin>>t;
	// while (t--){
	// 	int n = 9;
	//  	cin>>n;
	//  	n = largestPower(n) - 1;
	//  	cout<<cache[n]<<endl;
	//  }
 return 0;
}