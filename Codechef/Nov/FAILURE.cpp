#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>

using namespace std;

bool isCyclicUtil(vector< vector< int > > &adj, int v, vector< bool > &visited, vector< bool > &recStack, int p, int z){ 
    if(!visited[v]) { 
        visited[v] = true, recStack[v] = true;
        for (int i=0; i<adj[v].size(); i++){
        	if ( !visited[adj[v][i]] && isCyclicUtil(adj, adj[v][i], visited, recStack, p, v)) {
                return true; 
        	}
            else if (recStack[adj[v][i]] && adj[v][i] != z){
                return true; 
            }
        }
  
    } 
    recStack[v] = false;
    return false;
} 

bool isCyclic(vector< vector< int > > &v, int n, int p){
	vector< bool > visited(n, false);
	vector< bool > recStack(n, false);
	if (p != -1){
		visited[p] = true;
	}
	for(int i = 0; i < n; i++){
		if (i == p) continue;
        if (isCyclicUtil(v, i, visited, recStack, p, -1)) 
            return true;
	}
		
    return false; 
}

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m, a, b;
		scanf("%d %d", &n, &m);
		vector< vector< int > > v(n);
		for (int i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			v[--a].push_back(--b);
			v[b].push_back(a);
		}


		int cyclenumber = 0; 
		vector< int > mark(n, false);
		vector< int > color(n, 0);
		vector< int > par(n, 0);
		vector< vector< int > > cycles(n);

		if (2*n-3 < m || !isCyclic(v, n, -1)){
			printf("-1\n");
		}else{
			int res = -1;
			for(int i = 0; i < n; i++){
				if (!isCyclic(v, n, i)){
					res = i+1;
					break;
				}
			}
			printf("%d\n", res);
		}
	}
 return 0;
}