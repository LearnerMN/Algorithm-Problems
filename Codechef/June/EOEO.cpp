#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>

using namespace std;


int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t>0){
	    int n;
	    cin >> n;
	    for(int i = 1; i <= n; i++){
	        if(i % 2 == 0){
	            for(int j = i*n; j > n*(i-1); j--){
	                cout << j << " ";
	            }
	        }
	        else{
	            if(i != 1){
	            for(int k = ((i-1) * n) + 1; k <= i*n; k++){
	                cout << k << " ";
	            }
	            }
	            else{
	                for(int k = 1; k <= n; k++){
	                    cout << k <<" ";
	                }
	            }
	        }
	        cout << "\n";
	    }
	    t--;
	}
	return 0;
}

/*
10
2 4 8 16


*/