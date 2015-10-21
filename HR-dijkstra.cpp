//https://www.hackerrank.com/contests/sict01/challenges/challenge-104/submissions/code/3938348
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii> > Graph;

void dijkstra(Graph &g, int s, vector<int> &prio) {
    int n = g.size();
    prio.assign(n, INT_MAX);
    prio[s] = 0;
    priority_queue<pii, vector<pii> , greater<pii> > q;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d != prio[u])
            continue;
        for (int i = 0; i < (int) g[u].size(); i++) {
            int v = g[u][i].first;
            int nprio = prio[u] + g[u][i].second;
            if (prio[v] > nprio) {
                prio[v] = nprio;
                q.push(make_pair(nprio, v));
            }
        }
    }
}

int main() {
	
	int T;
	cin>>T;
	for (int i=0; i<T; i++){
		int N,M,a,b;
		cin>>N>>M;
		Graph g(N);
		for (int k=0; k<M; k++){
			cin>>a>>b;
			--a;--b;
			g[a].push_back(make_pair(b, 6));
	    	g[b].push_back(make_pair(a, 6));
		}
	    int endV;
	    cin>>endV;
		endV--;
	    vector<int> prio;
	    dijkstra(g, endV, prio);
	
	    for (int i = 0; i<prio.size(); i++)
		    if (endV != i)
		        cout<<(prio[i] != INT_MAX ? prio[i] : -1)<<" ";
		cout<<endl;
	}
    
}
