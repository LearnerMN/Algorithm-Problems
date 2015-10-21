//http://www.spoj.com/CSMS/problems/ULS11202/
#include <cstdio>
#include <vector>

#define NN 100001
#define MM 2000001

struct chain{
	int v, cost;
	chain *next;
} *code[NN];

int N, M;
bool vis[NN];
int vist[NN], res, ans;

int dfs(int v, int c, int t, int p){
	if (vis[v]) 
		return  vist[v];
	vis[v] = true; 
	vist[v] = t;
	chain *abc = code[v];
	int ret = N;
	while (abc!=NULL){
		if (p != abc->v){
			res = dfs(abc->v, abc->cost, t+1, v);
			if (res < ret) 
				ret = res;
		}
		abc = abc->next;
	}

	if (ret >= vist[v]) 
		ans += c;
	return ret;
}
int main(){
	char cnt, c;
	chain * abc;
	int v, u, cost;
	scanf("%d %d\n", &N, &M);
	for (int i=0; i<M; i++){
		v=0; cost=0; u=0;
		while ((c=getchar()) && c!=' ') 
			v=((v<<3)+(v<<1))+c-'0';
		while ((c=getchar()) && c!=' ')
			u=((u<<3)+(u<<1))+c-'0';
		while ((c=getchar()) && c!='\n')
			cost++;
		abc = new chain;
		abc->v = u; 
		abc->cost = cost;
		abc->next = code[v]; 
		code[v] = abc;
		abc = new chain;
		abc->v = v; 
		abc->cost = cost;
		abc->next = code[u]; 
		code[u] = abc;
	}
	dfs (1, 0, 0, 0);
	printf("%d\n", ans);
	return 0;
}
