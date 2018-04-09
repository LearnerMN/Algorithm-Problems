#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>
#include <climits>
#include <cstdio>

#define xx first
#define yy second
#define pb push_back
#define mp make_pair

using namespace std;
int a[27];
int b[27];
int main(){
	string s1,s2;
	cin>>s2;
	cin>>s1;
	for (int i=0; i<s1.size(); i++){
		bool check = false;
		for (int k=0; k<s2.size(); k++){
			if (s1[i]==s2[k]){
				check = true;
				break;
			}
		}
		if (!check){
			cout<<-1<<endl;
			return 0;
		}
	}
	for (int i=0; i<s1.size(); i++){
		a[(int)s1[i]-97]++;
	}
	for (int i=0; i<s2.size(); i++){
		b[((int)s2[i])-97]++;
	}
	int sums = 0;
	for (int i=0; i<27; i++)
		sums += min(a[i],b[i]);
	cout<<sums<<endl;
 return 0;
}