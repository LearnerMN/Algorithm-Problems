//http://codeforces.com/problemset/problem/586/B
//
//  main.cpp
//  CF
//
//  Copyright © 2015 Khureltsooj. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int a[4][1001];
int main(int argc, const char * argv[]) {
    int n,x;
    cin>>n;
    
    for (int i=1; i<n; i++){
        cin>>x;
        a[0][i] = a[0][i-1] + x;
    }
    vector< int > v1;
    for (int i=0; i<n-1; i++){
        cin>>x;
        v1.push_back(x);
    }
    for (int i=v1.size()-1; i>=0; i--){
        a[2][i] = v1[i] + a[2][i+1];
    }
    vector< int > v;
    for (int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    
    for (int i=0; i<n; i++){
        a[1][i] = v[i] + a[0][i];
    }
    vector< int > lol;
    for (int i=n-1; i>=0; i--){
        lol.push_back(a[2][i]+a[1][i]);
    }
    sort(lol.begin(),lol.end());
    
    cout<<lol[1]+lol[0]<<endl;
    
    return 0;
}
