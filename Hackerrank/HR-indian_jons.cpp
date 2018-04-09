//https://www.hackerrank.com/contests/sict01/challenges/challenge-105/submissions/code/3938226
#include <iostream>
#include <vector>
using namespace std;

bool door_in_wall(vector<string> &wall,vector<string> &door){
	int R = wall.size();;
	int C = wall[0].size();;
	
	int r = door.size();;
	int c = door[0].size();
	
	
	for (int i=0; i<=R-r; i++){
		for (int j=0; j<=C-c; j++){
			
			bool check = true;
			for (int k=0; k<r; k++){
				for (int p=0; p<c; p++){
					if (wall[i+k][j+p] != door[k][p]){
						check = false;
						break;
					}
				}
				if (!check) break;
			}
			if (check)
				return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	for (int i=0; i<t; i++){
		vector<string> wall,door;
		int n,m;
		cin>>n>>m;
		for (int j=0; j<n; j++){
			string tmp;
			cin>>tmp;
			wall.push_back(tmp);
		}
		int r,c;
		cin>>r>>c;
		for (int j=0; j<r; j++){
			string tmp;
			cin>>tmp;
			door.push_back(tmp);
		}
		cout<<(door_in_wall(wall,door) ? "YES" : "NO")<<endl;
	}
	
	return 0;
}
