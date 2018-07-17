#include<bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d\n",x)
#define pb(x) push_back(x)
#define lim 1010
#define INF 1000000000

/*
	single source shortest path : bellam ford
*/

struct edge {
	int u;int v;
	int w;
};

vector<edge> edges;
int n,e,i,j,src,u,v,w;
int dist[lim];

void pre() {
	edges.clear();
	for(i=0;i<lim;i++) {
		dist[i]=INF;
	}
}

bool bellamford() {
	dist[src]=0;
	for(j=0;j<n-1;j++) {
		for(i=0;i<e;i++) {
			if(dist[edges[i].u]+edges[i].w<edges[i].v) {
				dist[edges[i].v]=dist[edges[i].u]+edges[i].w;
			}
		}
	}
	for(i=0;i<e;i++) {
		if(dist[edges[i].u]+edges[i].w<edges[i].v) {
			return false;
		}
	}
	return true;
}

int main() {
	pre();
	sd(n);sd(e);sd(src);
	for(i=0;i<e;i++) {
		sd(u);sd(v);sd(w);
		edges.pb(((edge){u,v,w}));
	}
	bellamford();
	return 0;
}