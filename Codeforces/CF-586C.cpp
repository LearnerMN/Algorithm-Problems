//http://codeforces.com/problemset/problem/586/C
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <functional>
using namespace std;

int N, V[4001], D[4001], P[4001];

int main () {

	cin >> N;

	for (int i=0; i<N; ++i)
		scanf("%d %d %d", V+i, D+i, P+i);

	vector<int> treated ;
	for (int i=0; i<N; ++i) {
		if (P[i] >= 0) {
			treated.push_back(i);
			priority_queue<int, vector<int>, greater<int> > q;

			for (int j=i+1; V[i]>0 && j<N; ++j) {
				if (P[j] >= 0) {
					P[j] -= V[i];
					--V[i];
					if (P[j]<0) 
						q.push(j);
				}
			}


			while(!q.empty()) {
				int cur = q.top(); q.pop();
				for (int j=cur+1; j<N; ++j) {
					if (P[j] >= 0) {
						P[j] -= D[cur];
						if (P[j] < 0)
							q.push(j);
					}
				}
			}
		}
	}

	cout << treated.size() << endl;
	for (int i=0; i<treated.size(); ++i)
		cout << treated[i]+1 << " ";
	cout << endl;


	return 0;
}
