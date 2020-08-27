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
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isVowel(char &ch){
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

double powerZ(double x, int y){  
    double temp;  
    if(y == 0)  
        return 1;  
    temp = powerZ(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        if(y > 0)  
            return x * temp * temp;  
        else
            return (temp * temp) / x;  
    }  
}  

bool isAZ(string &s){ 
	int n = s.size();
	int c = 0;
	for (int i=0; i<n; i++){
		bool check = isVowel(s[i]);
		c += check;
		if (!check && i-1 >= 0 && !isVowel(s[i-1])){
			return false;
		}
		if (!check && i-2 >= 0 && !isVowel(s[i-2])){
			return false;
		}
	}
	
	return (n+1)/2 <= c;
} 
int main(){
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--){
		int n, a = 0, b = 0;
		scanf("%d", &n);
		vector< double> mpA(26, 0);
		vector< double> mpB(26, 0);
		vector< double> mpAC(26, 0);
		vector< double> mpBC(26, 0);
		for (int i=0; i<n; i++){
			string s;
			cin>>s;
			vector< double> sp(26, 0);
			for (auto ch : s){
				sp[(int)ch - 97]++;
			}
			bool isA = isAZ(s);
			if (isA){
				a++;
				for (int i=0; i<26; i++){
					if (sp[i] > 0){
						mpAC[i]++;
						mpA[i] += sp[i];	
					}
				}
			}else{
				b++;
				for (int i=0; i<26; i++){
					if (sp[i] > 0){
						mpBC[i]++;
						mpB[i] += sp[i];	
					}
				}
			}
		}
		long double inf = 10000000;
		vector< long double > x, y;
		for (int i=0; i<26; i++){
			if (mpA[i] > 0){
				x.push_back(mpAC[i]);
				y.push_back(powerZ(mpA[i], a));
			}
			if (mpB[i] > 0){
				y.push_back(mpBC[i]);
				x.push_back(powerZ(mpB[i], b));
			}
		}

		long double ratio = 1;
		while (!x.empty() && !y.empty()){
			if (ratio < inf){
				ratio *= x.back(); x.pop_back();
			}else{
				ratio /= y.back(); y.pop_back();
			}
		}

		if (ratio > inf && y.empty()){
			
		}else{
			while (!y.empty()){
				ratio /= y.back(); y.pop_back();
			}
			while (!x.empty() and ratio < inf){
				ratio *= x.back(); x.pop_back();
			}
		}
		if (ratio > inf)
			puts("Infinity");
		else{
			printf("%.7Lf\n", ratio);			
		}

	}
 return 0;
}