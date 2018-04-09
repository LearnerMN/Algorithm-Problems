#include <iostream>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int toInt(string s){
	int num;
	stringstream z(s);
	z >> num;
	return num;
}
int a,b,c;
int x=0,y=0,z=0;
void dfs(){
	if (max(a,max(b,c))==0){
		return;
	}
	if (max(a,max(b,c))==c){
		if (a>b){
			a--;
			z++;
			c--;
			return dfs();
		}else{
			b--;
			c--;
			y++;
			return dfs();
		}
	}
	if (max(a,max(b,c))==b){
		if (a>c){
			b--;
			a--;
			x++;
			return dfs();
		}else{
			c--;
			b--;
			y++;
			return dfs();
		}
	}
	if (max(a,max(b,c))==a){
		if (b>c){
			b--;
			a--;
			x++;
			return dfs();
		}else{
			c--;
			a--;
			z++;
			return dfs();
		}
	}
}
int main(){
	cin>>a>>b>>c;
	dfs();
	if (a>=0 && b>=0 && c>=0)
		cout<<x<<" "<<y<<" "<<z<<endl;
	else
		cout<<"Impossible"<<endl;
	
 return 0;
}