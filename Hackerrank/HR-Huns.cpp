//https://www.hackerrank.com/contests/open-cup-mongolia-2014/challenges/khuns/submissions/code/1211376
#include <iostream>
//#include <cstdio>
#include <climits>
#include <stack>
#include <vector>
#include <algorithm>
#define ull unsigned long long

using namespace std;
vector<string> v;
bool used[151][151];
int R,C;
int upDot(){
	int c=0;
	for (int i=1; i<=C; i++){
		if (v[1][i]=='.' || v[1][i]=='D'){
			c++;
		}
	}
	return c;
}
int downDot(){
	int c=0;
	for (int i=1; i<=C; i++){
		if (v[R][i]=='.' || v[R][i]=='D'){
			c++;
		}
	}
	return c;
}
int leftDot(){
	int c=0;
	for (int i=1; i<=R; i++){
		if (v[i][1]=='.' || v[i][1]=='D'){
			c++;
		}
	}
	return c;
}

int rightDot(){
	int c=0;
	for (int i=1; i<=R; i++){
		if (v[i][C]=='.' || v[i][C]=='D'){
			c++;
		}
	}
	return c;
}
bool up(int x,int y){
	return v[x-1][y]=='.';
}
bool down(int x,int y){
	return v[x+1][y]=='.';
}
bool left(int x,int y){
	return v[x][y-1]=='.';
}
bool right(int x,int y){
	return v[x][y+1]=='.';
}
int main(){
	int u=0,l=0,d=0,r=0;
	string st;
	cin>>R>>C;
	string str = "";
	for (int i=0; i<C+2; i++){
		str += ".";
	}
	v.push_back(str);
	for (int i=0; i<R; i++){
		cin>>st;
		st = "." + st + "."; 
		v.push_back(st);
	}
	v.push_back(str);
	for (int i=1; i<=R; i++){
		for (int k=1; k<=C; k++){
			if (v[i][k]=='D'){
				if (up(i,k)) u++;
				if (down(i,k)) d++;
				if (left(i,k)) l++;
				if (right(i,k)) r++;
			}
		}
	}
	cout<<min(r,rightDot()) + min(l,leftDot()) + min(d,downDot()) + min(u,upDot())<<endl;
	//cout<<u<<" "<<d<<" "<<l<<" "<<r<<endl;
	
	return 0;
}

/*
7 8
XXX..XXX
XXX..XXX
.....XXX
XXX..XXX
XDDDD.XX
XDDDD...
XXXXXXXX

*/
