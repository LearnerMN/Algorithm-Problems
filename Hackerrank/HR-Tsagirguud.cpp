//https://www.hackerrank.com/contests/sict02/challenges/challenge-134/submissions/code/4013935
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    int a,c = 0;
    cin >> a;
    for ( int i = 1; i < n; i++ ){
        int b;
        cin >> b;
        if ( a <= b )
            c++;
        a = b;
    }
    cout << c << endl;
    return 0;
}
