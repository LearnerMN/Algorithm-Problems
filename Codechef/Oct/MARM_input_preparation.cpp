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


int main(){
	freopen("input.txt", "w", stdout);

	int t = rand() % 70 + 1;
	cout<<t<<endl;
	while (t--){
		int n = rand() % 10000 + 1;
		long long k = rand() % 100000 + 1;
		cout<<n<<" "<<k<<endl;
		for (int i=0; i<n; i++){
			if (i != 0)
				cout<<" ";
			cout<<(rand() % 1000000 + 1);
		}
		cout<<endl;
	}
 return 0;
}
/*


6
4 4
1 2 3 4
4 8
1 2 3 4
4 12
1 2 3 4
4 16
1 2 3 4
4 20
1 2 3 4
4 207
1 2 3 4




5 1 2 1 
4 3 1 5 
1 2 3 4 
5 1 2 1 
4 3 1 5 
5 1 2 4 

*/