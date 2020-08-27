#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map> 

using namespace std;


int main(){
	freopen("input.txt", "r", stdin);

	int t;
	scanf("%d", &t);
	while (t--){
		int n, a, c;
		scanf("%d", &n);
		int res = 0;
		scanf("%d", &a);
		int maxs = a;
		unordered_map<int,int> mp;
		mp[a]++;
		vector< int > x(1000);
    	for (int j=1; j<1000; j++){
			x[j] += (a % j == 0);
		}
		for (int i=1; i<n; i++){
			scanf("%d", &a);
			c = 0;
			if (a < 1000){
				c = x[a];
			}else{
			    for (int j=a; j<=maxs; j += a){
			        if (mp.find(j) != mp.end()){
			            c += mp[j];
			        }
			    }
			    maxs = max(maxs, a);
			}
			res = max(res, c);	
		    mp[a]++;
		    for (int j=1; j<1000; j++){
				x[j] += (a % j == 0);
			}
		}
		printf("%d\n", res);
	}
 return 0;
}
/*
1| 3 * 1
2| 2 * 3
3| 1 * 2
4| 3 * 1
5| 2 * 3
2 3 
[Finished in 0.9s]

*/