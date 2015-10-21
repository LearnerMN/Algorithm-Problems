//httpwww.spoj.comCSMSproblemsCSMS144
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

int main(){
	int a[19] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489};
	int b[19];
	int n,c=0,sums=0;
	scanf("%d",&n);
	for (int i=0; i<(1<<19); i++){
		c=0,sums = 0;
		for (int j=0; j<19;j++){
			if ((1<<j)&i){
				sums += a[j];
				b[c++] = a[j];
			}
		}
		if (sums == n){
			printf("%d = %d",sums,b[0]);
			for (int k=1; k<c;k++){
				printf(" + %d",b[k]);
			}
			return 0;
		}
	}
	printf("Miss");
 return 0;
}
