#include<bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d\n",x)
#define pb(x) push_back(x)
#define lim 1010

int n,k,i,j;
int g[lim][lim];
int d[lim][lim];

/*
	All pair shortest path problem : floyd warshall
	test case :
	4
	0 5 9999 10
	9999 0 3 9999
	9999 9999 0 1
	9999 9999 9999 0
*/

void pre() {
	for(i=0;i<lim;i++) {
		for(j=0;j<lim;j++) {
			d[i][j]=g[i][j];
		}
	}
}

void floydwarshall() {
	for (k=0;k<n;k++) {
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                if (d[i][k]+d[k][j]<d[i][j]) {
                	d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
}

void printRes() {
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			pd(d[i][j]);
		}
		printf("\n");
	}
}

int main() {
	sd(n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			sd(g[i][j]);
		}
	}
	pre();
	floydwarshall();
	printRes();
	return 0;
}