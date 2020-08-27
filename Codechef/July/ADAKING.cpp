#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>
#include <queue>

using namespace std;

bool isValid(int x, int y){
	return 0 <= x && x < 8 && 0 <= y && y < 8;
}

void signSpot(vector<vector<int>> &v, int n){
	vector<int> x = { -1, -1, -1, 0, 1, 1,  1,  0 };
	vector<int> y = { -1,  0,  1, 1, 1, 0, -1, -1 };

	queue<pair<int,int>> q;
		
	q.push(make_pair(0, 0));

	int counter = 0;
	while (!q.empty()){
		auto p = q.front(); q.pop();
		if (v[p.first][p.second] != 0) continue;

		v[p.first][p.second] = 1;
		counter++;
		if (counter == n){
			return;
		}
		for (int i=0; i<8; i++){
			int tx = p.first + x[i];
			int ty = p.second + y[i];
			if (isValid(tx, ty) && v[tx][ty] == 0){
				q.push(make_pair(tx, ty));
			}
		}
	}
}

void addObstacle(vector<vector<int>> &v){
	vector<int> x = { -1, -1, -1, 0, 1, 1,  1,  0 };
	vector<int> y = { -1,  0,  1, 1, 1, 0, -1, -1 };

	for (int i=0; i<8; i++){
		for (int j=0; j<8; j++){
			if (v[i][j] != 0) continue;

			for (int k=0; k<8; k++){
				int tx = i + x[k];
				int ty = j + y[k];
				if (isValid(tx, ty) && v[tx][ty] == 1){
					v[i][j] = 2;
				}
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector<vector<int>> v(8, vector<int>(8, 0));
		signSpot(v, n);
		addObstacle(v);
		v[0][0] = 3;
		for (int i=0; i<8; i++){
			for (int j=0; j<8; j++){
				// cout<<v[i][j];
				if (v[i][j] == 3){
					cout<<"O";
				}else if (v[i][j] == 2){
					cout<<"#";
				}else{
					cout<<".";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
