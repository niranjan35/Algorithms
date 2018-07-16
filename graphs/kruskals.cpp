#include<bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define pd(x) printf("%d",x)

#define lim 1010

struct edge {
	int u;int v;
	int w;
};

bool operator < (edge a, edge b) {
	return a.w<b.w;
}

int p[lim];
vector<edge> e;
int u,v,w,n,i,j;

/*
Minimum spanning tree : KRUSKALS
test case :
14
1 2 4 
1 8 8
2 8 11
2 3 8
8 9 7
8 7 1
3 9 2
7 9 6
3 4 7 
7 6 2
3 6 4
4 6 14
4 5 9
6 5 10
*/

int f(int x) {
	if(p[p[x]]!=p[x]) {
		p[x]=f(p[x]);
	}
	return p[x];
}

void kruskals() {
	printf("***\n");
	sort(e.begin(),e.end());
	for(i=1;i<=n;i++) {
		p[i]=i;
	}
	for(i=0;i<n;i++) {
		int x=f(e[i].u);
		int y=f(e[i].v);
		if(x==y) {
			continue;
		}
		else {
			printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
		}
		p[x]=y;
	}
}

int main() {
	sd(n);
	e.clear();
	for(i=0;i<n;i++) {
		sd(u);sd(v);sd(w);
		e.pb(((edge){u,v,w}));
	}
	kruskals();
	return 0;
}