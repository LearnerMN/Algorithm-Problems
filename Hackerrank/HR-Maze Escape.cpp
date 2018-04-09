//https://www.hackerrank.com/challenges/maze-escape/submissions/game/13195724
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int static logic = 1;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int player;
	vector<string>v(3);
	cin>>player>>v[0]>>v[1]>>v[2];
	if(v[2][2]=='#'&&v[1][2]!='#')cout<<"RIGHT"<<endl;
	else if(v[0][2]=='#'&&v[0][1]!='#')cout<<"UP"<<endl;
	else if(v[0][0]=='#'&&v[1][0]!='#')cout<<"LEFT"<<endl;
	else if(v[2][0]=='#'&&v[2][1]!='#')cout<<"DOWN"<<endl;
	else cout<<"UP"<<endl;
        
    return 0;
}

