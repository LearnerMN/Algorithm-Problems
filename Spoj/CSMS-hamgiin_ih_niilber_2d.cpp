//http://www.spoj.com/CSMS/files/src/11134765/
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
int a[101][101];
int sequence(std::vector<int> const & numbers){
    int max_so_far  = numbers[0], max_ending_here = numbers[0];
    for(size_t i = 1; i < numbers.size(); i++){
        if(max_ending_here < 0){
            max_ending_here = numbers[i];
        }else{
             max_ending_here += numbers[i];
        }
        if(max_ending_here >= max_so_far ){
            max_so_far  = max_ending_here;
        }
    }
    return max_so_far ;
}
int main(){
	//freopen("#6.in", "r", stdin);
	//freopen("#6.out", "w", stdout);
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		for (int k=0; k<n; k++)
			scanf("%d",&a[i][k]);
	}
	
	int sums=0;
	int maxs = INT_MIN;
	for (int i=n-1; i>=0; i--){
		for (int j=0; j<n-i; j++){
			vector< int > v;
			for (int p=0; p<n; p++){
				sums = 0;
				for (int k=j; k<=j+i; k++){
					//cout<<p<<k<<" ";
					sums += a[p][k];
				}
				v.push_back(sums);
				//cout<<endl;
			}
			maxs = max(maxs,sequence(v));
		}
	}
	cout<<maxs<<endl;
 return 0;
}
