// https://train.usaco.org/usacoprob2?a=iv2UF2vraH3&S=milk2

/*
ID: learner2
LANG: C++11
PROB: namenum
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
#include <fstream>
#include <set>

using namespace std;

map< char, vector< char > > mp;
set< string > ss;
bool isEmpty = true;
void dfs(string &num, int ind, string res){
	if (res.size() == num.size()){
		if (ss.find(res) != ss.end()){
			isEmpty = false;
			cout<<res<<endl;	
		}
		return;
	}
	for (int j=0; j<3; j++){
		dfs(num, ind + 1, res + mp[num[ind]][j]);
	}
}

int main(){
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	ifstream fdic("dict.txt");

	mp['2'] = { 'A', 'B', 'C' };
	mp['3'] = { 'D', 'E', 'F' };
	mp['4'] = { 'G', 'H', 'I' };
	mp['5'] = { 'J', 'K', 'L' };
	mp['6'] = { 'M', 'N', 'O' };
	mp['7'] = { 'P', 'R', 'S' };
	mp['8'] = { 'T', 'U', 'V' };
	mp['9'] = { 'W', 'X', 'Y' };

	string text;
	while (fdic>>text){
		ss.insert(text);
	}
	string num;
	cin>>num;

	dfs(num, 0, "");
	if (isEmpty) cout<<"NONE"<<endl;
 return 0;
}
