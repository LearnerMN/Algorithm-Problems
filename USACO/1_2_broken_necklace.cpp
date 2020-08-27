// https://train.usaco.org/usacoprob2?a=obK0bGbRCmM&S=beads

/*
ID: learner2
LANG: C++11
PROB: beads
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

int diff(map< char, vector< int > > &mp, int l, int r){
	int res = 0;
	for (char ch='a'; ch<='z'; ch++){
		int d = mp[ch][r+1] - mp[ch][l];
		// cout<<ch<<": "<<d<<endl;
		res += (d&1);
	}
	return res / 2;
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    map< char, vector< int > > mp;
    int n = s.size();
    for (char ch='a'; ch<='z'; ch++){
        for (int i=0; i<=n; i++){
            mp[ch].push_back(0);
        }
    }
    for (int i=1; i<=n; i++){
    	for (char ch='a'; ch<='z'; ch++){
    		mp[ch][i] = mp[ch][i-1] + (ch == s[i-1]);
    	}
    }
    
    // for (char ch='a'; ch<='z'; ch++){
    // 	cout<<ch<<": ";
    //     for (int i=0; i<=n; i++){
    //         cout<<mp[ch][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    vector< bool > res;
    for (auto q : queries){
        int l = q[0];
        int r = q[1];
        int k = q[2];

        int d = diff(mp, l, r);
        res.push_back(k >= d);
    }
    return res;
}
int main(){

	string s = "hunu";
	vector< vector< int > > q = { { 0, 3, 1} };
	vector< bool > res = canMakePaliQueries(s, q);
	for (auto r : res){
		cout<<r<<" ";
	}
	// freopen("beads.in", "r", stdin);
	// freopen("beads.out", "w", stdout);
	// int n = 29;
	// string s = "wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
	// cin>>n;
	// cin>>s;
	// s += s;
	// n *= 2;
	// int res = 0;

	// for (int i=1; i<n; i++){
	// 	//check left
	// 	int l = i-1;
	// 	char tmp = 'w';
	// 	int count = 0;
	// 	while (l >= 0){
	// 		if (s[l] != 'w' && tmp != 'w' && s[l] != tmp){
	// 			break;
	// 		}
	// 		count++;
	// 		if (s[l] == 'b' || s[l] == 'r'){
	// 			tmp = s[l];
	// 		}
	// 		l--;
	// 	}
	// 	int r = i;
	// 	tmp = 'w';
	// 	while (r < n){
	// 		if (s[r] != 'w' && tmp != 'w' && s[r] != tmp){
	// 			break;
	// 		}
	// 		count++;
	// 		if (s[r] == 'b' || s[r] == 'r'){
	// 			tmp = s[r];
	// 		}
	// 		r++;
	// 	}
	// 	res = max(res, count);
	// }
	// cout<<min(res, n/2)<<endl;
 return 0;
}
