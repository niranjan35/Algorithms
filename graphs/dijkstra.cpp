#include<bits/stdc++.h>
using namespace std;
/* 
test case :
9 14 0
0 1 4 
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
6 8 6
2 3 7 
6 5 2
2 5 4
3 5 14
3 4 9
5 4 10
*/

#define pb(x) push_back(x)
#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d\n",x)
#define INF 1000000000

struct edge {
	int v;
	int w;
};

bool operator < (edge a,edge b) {
	return a.w>b.w;
}

int dist[1010];
vector<edge> g[1010];
int u,v,n,e,i,src,w;

void pre() {
	for(i=0;i<1010;i++) {
		dist[i]=INF;
	}
	for(i=0;i<1010;i++) {
		g[i].clear();
	}
}

void dijkstra() {
	priority_queue<edge> q;
	q={};
	q.push(((edge){src,0}));
	dist[src]=0;
	while(!q.empty()) {
		edge p=q.top();
		q.pop();
		for(i=0;i<g[p.v].size();i++) {
			edge adj=g[p.v][i];
			if(dist[p.v]+adj.w<dist[adj.v]) {
				dist[adj.v]=dist[p.v]+adj.w;
				q.push((edge){adj.v,dist[adj.v]});
			}
		}
	}
}

int main() {
	pre();
	sd(n);sd(e);
	sd(src);
	for(i=0;i<e;i++) {
		sd(u);sd(v);sd(w);
		g[u].pb(((edge){v,w}));
		g[v].pb(((edge){u,w}));
	}
	dijkstra();
	for(i=0;i<1010;i++) {
		if(dist[i]!=INF) {
			printf("dist of %d = %d\n",i,dist[i]);
		}
	}
	return 0;
}