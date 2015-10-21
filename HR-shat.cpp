//https://www.hackerrank.com/contests/sict01/challenges/challenge-107/submissions/code/3938183
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        for (int j=n; j>0; j--){
            cout<<(j<=i ? "#" : " ");
        }
        cout<<endl;
    }
    return 0;
}
