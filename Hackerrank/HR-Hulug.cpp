//https://www.hackerrank.com/contests/open-cup-mongolia-2014/challenges/khulug/submissions/code/1211129
#include <iostream>
//#include <cstdio>
#include <climits>
#include <stack>
#include <vector>
#include <algorithm>
#define ull unsigned long long

using namespace std;

int main(){
	int R,C,A,B;
	cin>>R>>C;
	cin>>A>>B;
	for (int i=0; i<R; i++){
		if (i%2==0){
			for (int j=0; j<A; j++){
				for (int k=0; k<C; k++){
					if (k%2==0)
						for (int p=0; p<B; p++){
							cout<<'X';
						}
					else
						for (int p=0; p<B; p++){
							cout<<'.';
						}
				}
				cout<<endl;
			}	
		}else{
			for (int j=0; j<A; j++){
				for (int k=0; k<C; k++){
					if (k%2==0)
						for (int p=0; p<B; p++){
							cout<<'.';
						}
					else
						for (int p=0; p<B; p++){
							cout<<'X';
						}
				}
				cout<<endl;
			}	
		}
		
	}
	
	return 0;
}
