#include<bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define pf(x) printf("%d\n",x)
#define INF 1000000000
#define lim 1010

/*
Sorting : quick sort
test case : 
10
5 4 6 2 1 7 8 9 11 17
*/

int arr[lim];
int n;

void printarr() {
	for(int i=0;i<n;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int partition(int s,int e) {
	int ptr=s-1;
	int tmp;
	int pivot=e;
	for(int i=s;i<e;i++) {
		if(arr[i]<arr[pivot]) {
			ptr++;
			tmp=arr[ptr];
			arr[ptr]=arr[i];
			arr[i]=tmp;
		}
	}
	ptr++;
	tmp=arr[pivot];
	arr[pivot]=arr[ptr];
	arr[ptr]=tmp;
	return ptr;
}

void quicksort(int s,int e) {
	if(s<e) {
		int pi=partition(s,e);
		quicksort(s,pi-1);
		quicksort(pi+1,e);
	}
}

int main() {
	sd(n);
	for(int i=0;i<n;i++) {
		sd(arr[i]);
	}
	quicksort(0,n-1);
	printarr();
	return 0;
}