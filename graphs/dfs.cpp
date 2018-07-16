#include<bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d\n",x)
#define INF 1000000000

bool visited[1010];
vector<int> g[1010];
int u,v,n,e,i,src;

void pre() {
	memset(visited,0,sizeof(visited));
	for(i=0;i<1010;i++) {
		g[i].clear();
	}
}

void dfs(int src) {
	pd(src);
	visited[src]=1;
	for(i=0;i<g[src].size();i++) {
		if(!visited[g[src][i]]) {
			visited[g[src][i]]=1;
			dfs(g[src][i]);
		}
	}
}

int main() {
	sd(n);sd(e);
	sd(src);
	for(i=0;i<e;i++) {
		sd(u);sd(v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(src);
	return 0;
}