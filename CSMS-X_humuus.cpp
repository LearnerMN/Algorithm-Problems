//http://www.spoj.com/CSMS/problems/CSMS142/
#include <stdio.h>
#include <iostream>

#include <string.h>

using namespace std;

string x,y;
int c[10002][10002];
int n, m;

void calc(){
	int i, j;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
  			if(x[i]==y[j]){
     			c[i][j]=c[i-1][j-1]+1;
     		}
     		else{
     			if(c[i-1][j]>=c[i][j-1])
        			c[i][j]=c[i-1][j];
        		else 
					c[i][j]=c[i][j-1];
     		}
  		}
	}
}

int main(){
	cin>>x>>y;
	m=x.size();
    n=y.size();
	x.insert(x.begin(),'*');
	y.insert(y.begin(),'*');
   	calc();
	printf("%d", c[m][n]);
	return 0;
}
