//https://www.hackerrank.com/contests/open-cup-mongolia-2014/challenges/1-1/submissions/code/1211440
#include <iostream>
//#include <cstdio>
#include <climits>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
long h[5001];
int main(){
	int n,k;
	cin>>n>>k;
	cin>>h[0];
	int d = 0;
	for (int i=1; i<n; i++){
		cin>>h[i];
		d = h[i] - h[i-1];
	}
	for (int i=n; i<n+k; i++){
		h[i] = h[i-1] + d;
		cout<<h[i]<<" ";
	}
	return 0;
}
