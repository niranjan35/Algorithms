#include<bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d\n",x)
#define pb(x) push_back(x)
#define INF 1000000000

/*
Minimum spanning tree : PRIMS
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

struct edge {
	int v;
	int w;
};

bool operator <(edge a, edge b) {
	return a.w>b.w;
}

int n,i,j,e,src,u,v,w;
vector<edge> g[1010];
bool visited[1010];

void pre() {
	for(i=0;i<1010;i++) {
		visited[i]=0;
		g[i].clear();
	}
}

void prims() {
	priority_queue<edge> q;
	q={};
	q.push((edge){src,0});
	int cnt=n-1;
	while(!q.empty()) {
		edge p=q.top();
		q.pop();
		if(!visited[p.v]) {
			cout<<p.v<<" "<<p.w<<endl;
			if(n<=0) {
				break;
			}
			n--;
			visited[p.v]=1;
			for(i=0;i<g[p.v].size();i++) {
				edge tmp=g[p.v][i];
				if(!visited[tmp.v]) {
					cout<<"pushed "<<tmp.v<<" "<<tmp.w<<endl;
					q.push(tmp);	
				}
			}
		}
	}
}

int main() {
	pre();
	sd(n);sd(e);sd(src);
	for(i=0;i<e;i++) {
		sd(u);sd(v);sd(w);
		g[u].pb(((edge){v,w}));
		g[v].pb(((edge){u,w}));
	}
	prims();
	return 0;
}