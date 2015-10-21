//https://www.hackerrank.com/contests/sict01/challenges/2-5/submissions/code/3938312
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char changeChar(char ch,int k){
    if ('A' <= ch && ch <= 'Z'){
        if (ch + k > 'Z'){
            k = ch + k - 'Z'-1;
            ch = 'A';
        }
        return ch + k;
    }else if('a' <= ch && ch <= 'z'){
        if (ch + k > 'z'){
            k = ch + k - 'z'-1;
            ch = 'a';
        }
        return ch + k;
    }else{
        return ch;
    }
}
int main() {
    int n;
    cin>>n;
    string st;
    cin>>st;
    int k;
    cin>>k;
    for (int i=0; i<n; i++){
        st[i] = changeChar(st[i],k%26);
    }
    cout<<st<<endl;
    return 0;
}
