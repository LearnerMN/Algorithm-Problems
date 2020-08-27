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

int MAX_BASE = 36;

int val(char c){ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 
  
long long toDeci(int base, string &str){ 
    int len = str.size(); 
    long long power = 1;
    long long num = 0;
    long long limit = 1000000000000;
    for (int i = len - 1; i >= 0; i--){ 
        if (val(str[i]) >= base){ 
           return -1; 
        } 
        num += val(str[i]) * power; 
        // if (num > limit){
        // 	return -1;
        // }
        power = power * base; 
    } 
    return num; 
} 
  
long long findAnswer(vector<vector<long long>> &code, int n){
	long long mins = 1000000000001;
	for (int k=2; k<MAX_BASE; k++){
		long long c = code[0][k];
		if (c == -1) continue;
		int i=1;
		bool found = false;
		for (; i<n; i++){
			found = false;
			for (int x=2; x<MAX_BASE; x++){
				if (code[i][x] == c){
					found = true;
					break;
				}
			}
			if (!found) break;
		}

		if ((found || n == 1) && i == n){
			mins = min(mins, c);
		}
	}
	
	return mins == 1000000000001 ? -1 : mins;
}

void print(vector<vector<long long>> &code){
	for (auto row : code){
		for (auto cell : row){
			cout<<cell<<" ";
		}
		cout<<endl;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	// freopen("marm_02.txt", "w", stdout);
	int t;
	cin>>t;
	while (t--){
		int n, a;
		string b;
		cin>>n;
		vector<vector<long long>> code(n, vector<long long>(MAX_BASE, -1));
		for (int i=0; i<n; i++){
			cin>>a>>b;
			if (a == -1){
				for (int k=2; k<MAX_BASE; k++){
					code[i][k] = toDeci(k, b);
				}
			}else{
				code[i][a] = toDeci(a, b);
			}
		}

		// print(code);
		cout<<findAnswer(code, n)<<endl;
	}
 return 0;
}