//http://codeforces.com/problemset/problem/586/A
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector< int > v(n);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    while (v.size()>0 && v[0] == 0){
        v.erase(v.begin());
    }
    while (v.size()>0 && v[v.size()-1] == 0){
        v.pop_back();
    }
    int c = 0,t = 0;
    for (int i=0; i<v.size(); i++){
        if (v[i] == 1){
            if (c == 1){
                t++;
            }
            c = 0;
            t++;
        }else{
            c++;
        }
    }
    cout<<t<<endl;
    return 0;
}
