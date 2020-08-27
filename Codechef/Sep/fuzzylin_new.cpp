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
    int n = 5;
    // cin>>n;
    vector< int > v = { 2, 4, 3, 5, 6 }; //(n);
    // for (int i=0; i<n; i++){
    //     cin>>v[i];
    // }
    int q = 1, k = 0;
    // cin>>q;
    while (k++ < 100){
        // cin>>k;
        int m = 0;
        int sum=0, c=0;
    //         // map< int, int > mp;
        for (int j=0; j<n; j++){
            if (v[j] > k || k%v[j] != 0){
                c++;
            }else{
                c = 0;
            }
        }
        m += (c*(c+1))/2;
        cout<<(n*(n+1)/2-m)<<endl;
    }
 return 0;
}