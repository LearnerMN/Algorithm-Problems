// https://train.usaco.org/usacoprob2?a=Ctq6fKPcl2J&S=palsquare

/*
ID: learner2
LANG: C++11
PROB: palsquare
*/

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

pair< int,int > bigPower(int n, int k){
	int t = 1;
	int c = 0;
	while (n >= t*k){
		t *= k;
		c++;
	}
	cout<<"("<<t<<","<<c<<")"<<endl;
	return make_pair(t, c);
}

int main(){
	// freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	int B = 10;
	int n = 25;
	while (n > 0){
		auto p = bigPower(n, 2);
		n -= p.first;
	}
 return 0;
}
