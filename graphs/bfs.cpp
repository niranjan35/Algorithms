#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define sd(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define pd(x) printf("%d\n",x)

vector<int> g[1010];
bool visited[1010];
int t,i,j,n,e,src,u,v;

void pre() {
	memset(visited,0,sizeof(visited));
	for(i=0;i<1010;i++) {
		g[i].clear();
	}
}

void bfs() {
	queue<int> q;
	q={};
	q.push(src);
	visited[src]=1;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		pd(x);
		for(i=0;i<g[x].size();i++) {
			if(!visited[g[x][i]]) {
				visited[g[x][i]]=1;
				q.push(g[x][i]);
			}
		}
	}
}

int main() {
	pre();
	sd(n);sd(e);
	sd(src);
	for(i=0;i<e;i++) {
		sd(u);sd(v);
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs();
	return 0;
}