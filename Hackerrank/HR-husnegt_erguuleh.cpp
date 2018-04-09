//https://www.hackerrank.com/contests/sict01/challenges/challenge-106/submissions/code/3938470
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void func(vector< vector< int > > &v,int n,int m,int r,int t){
	vector< int > ssp;
	for (int i=r; i<n-r; i++){
		ssp.push_back(v[i][r]);
	}
	for (int j=r+1; j<m-r; j++){
		ssp.push_back(v[n-1-r][j]);
	}
	for (int i=n-1-r-1; i>=r; i--){
		ssp.push_back(v[i][m-1-r]);
	}
	for (int j=m-1-r-1; j>r; j--){
		ssp.push_back(v[r][j]);
	}
	// swap matrix clock
	for (int i = 0; i<t; i++){
		int tmp = ssp.back();
		ssp.pop_back();
		ssp.insert(ssp.begin(),tmp);
	}
	
	for (int i=r; i<n-r; i++){
		int tmp = ssp[0];
		ssp.erase(ssp.begin());
		v[i][r] = tmp;
	}
	for (int j=r+1; j<m-r; j++){
		int tmp = ssp[0];
		ssp.erase(ssp.begin());
		v[n-1-r][j] = tmp;
	}
	for (int i=n-1-r-1; i>=r; i--){
		int tmp = ssp[0];
		ssp.erase(ssp.begin());
		v[i][m-1-r] = tmp;
	}
	for (int j=m-1-r-1; j>r; j--){
		int tmp = ssp[0];
		ssp.erase(ssp.begin());
		v[r][j] = tmp;
	}
}

void input(){
	int n,m,r;
	cin>>n>>m>>r;
	vector< vector< int > > v;
	for (int i=0; i<n; i++){
		vector<int> tmp(m);
		for (int j=0; j<m; j++){
			cin>>tmp[j];
		}
		v.push_back(tmp);
	}
    int x = min(n,m)/2;
    for (int i=0; i<x; i++){
    	func(v,n,m,i,r);
	}
	
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	input();
	
	return 0;
}
