//http://www.spoj.com/CSMS/problems/CSMS139/
#include <climits>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int tool[51][51];
int a[51][51][51]; 
int mass[101]; 
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++){
				scanf("%d",&a[i][j][k]);
			}
	int maxs = INT_MIN;
	for(int i = 0; i < n; i++) {
		memset(tool, 0, sizeof(tool));
		for(int p = i; p < n; p++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					tool[j][k] += a[p][j][k];
				}
			}
			int maxS = INT_MIN;
		    for (int x = 0; x < n; ++x) {
		        memset(mass, 0, sizeof(mass));
		        for (int y = x; y < n; ++y) {
		            for (int i = 0; i < n; ++i) {
		                mass[i] += tool[i][y];
		            }
		            int mx,sums;
				    mx = sums = mass[0];
				    for (int i = 1; i < n; ++i) {
				        if (sums < 0)
				            sums = mass[i];
				        else
				            sums += mass[i];
				        mx = max(mx, sums);
				    }
		            maxS = max(maxS,mx);
		        }
		    }
			maxs = max(maxs, maxS);
		}
	}
	printf("%d\n", maxs);
	return 0;
}
