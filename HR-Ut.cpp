//https://www.hackerrank.com/contests/sict02/challenges/challenge-133
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,a,b,s=0,c=1;
    cin>>n>>a>>b;
    while (n > s+a){
        s += (a-b);
        c += 2;
    }
    cout << c << endl;
    return 0;
}

